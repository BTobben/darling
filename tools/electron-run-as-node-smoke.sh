#!/usr/bin/env bash
set -u

usage() {
    cat <<'USAGE'
Usage: tools/electron-run-as-node-smoke.sh [--dry-run] [--skip-worker] <darling-path-to-electron-binary>

Runs a non-GUI Electron/Node smoke sequence under Darling using
ELECTRON_RUN_AS_NODE=1. The binary path must be visible inside the Darling
prefix, for example /Users/me/Downloads/electron-smoke/Electron.app/Contents/MacOS/Electron.

The script does not download or vendor Electron. If the supplied binary is
missing inside the Darling prefix, the Electron probes are reported as
skipped/missing external binary rather than treated as a destructive failure.

Environment:
  DPREFIX defaults to $HOME/.darling-xephyr if unset.
USAGE
}

DRY_RUN=0
SKIP_WORKER=0
BINARY=""

while [ "$#" -gt 0 ]; do
    case "$1" in
        --help|-h)
            usage
            exit 0
            ;;
        --dry-run)
            DRY_RUN=1
            shift
            ;;
        --skip-worker)
            SKIP_WORKER=1
            shift
            ;;
        --)
            shift
            break
            ;;
        -*)
            echo "unknown option: $1" >&2
            usage >&2
            exit 2
            ;;
        *)
            BINARY="$1"
            shift
            ;;
    esac
done

if [ -z "$BINARY" ] && [ "$#" -gt 0 ]; then
    BINARY="$1"
fi

: "${DPREFIX:=$HOME/.darling-xephyr}"
export DPREFIX

run_step() {
    local name="$1"
    shift
    local log_base
    log_base="${TMPDIR:-/tmp}/darling-electron-smoke.${name//[^A-Za-z0-9_.-]/_}.$$"

    echo "==> $name"
    echo "+ $*"
    if [ "$DRY_RUN" -eq 1 ]; then
        echo "dry-run: skipped"
        return 0
    fi

    "$@" >"$log_base.stdout" 2>"$log_base.stderr"
    local status=$?
    echo "status=$status"
    sed 's/^/stdout: /' "$log_base.stdout"
    sed 's/^/stderr: /' "$log_base.stderr" >&2
    rm -f "$log_base.stdout" "$log_base.stderr"
    return "$status"
}

DARLING_BIN="${DARLING_BIN:-darling}"
FAILURES=0

run_step "darling-shell-baseline" "$DARLING_BIN" shell echo darling-shell-ok || FAILURES=$((FAILURES + 1))

if [ -z "$BINARY" ]; then
    echo "skipped/missing external binary: no Electron binary path supplied"
    exit "$FAILURES"
fi

if [ "$DRY_RUN" -eq 0 ]; then
    if ! "$DARLING_BIN" shell /bin/test -x "$BINARY" >/dev/null 2>&1; then
        echo "skipped/missing external binary: $BINARY"
        exit "$FAILURES"
    fi
else
    echo "dry-run: would check executable inside Darling prefix: $BINARY"
fi

run_node_probe() {
    local name="$1"
    local script="$2"
    run_step "$name" "$DARLING_BIN" shell env ELECTRON_RUN_AS_NODE=1 "$BINARY" -e "$script" || FAILURES=$((FAILURES + 1))
}

run_node_probe "electron-process-versions" 'console.log(JSON.stringify(process.versions, null, 2))'
run_node_probe "electron-fs-readdir-root" 'const fs=require("fs"); console.log(fs.readdirSync("/").join("\n"))'
run_node_probe "electron-timers" 'setImmediate(()=>console.log("immediate-ok")); setTimeout(()=>console.log("timeout-ok"), 10)'

if [ "$SKIP_WORKER" -eq 0 ]; then
    run_node_probe "electron-worker-threads" 'const {Worker}=require("worker_threads"); const w=new Worker("console.log(\\"worker-ok\\")", {eval:true}); w.on("exit", code=>{ console.log("worker-exit", code); process.exitCode=code; }); w.on("error", err=>{ console.error(err && err.stack || err); process.exitCode=1; });'
else
    echo "skipped worker_threads probe by request"
fi

exit "$FAILURES"
