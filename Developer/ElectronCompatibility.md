# Electron compatibility validation under Darling

This document records the current non-GUI validation path for Electron,
Chromium, and Node startup work. It is intentionally staged so compatibility
work can move beyond ad hoc app launches.

Cloud CI and Codex Cloud can inspect/build this repository, but they cannot
validate GUI runtime behavior. GUI validation still needs a local Darling
machine with an initialized prefix and, for visible windows, an X11 session.

## Local environment

```sh
export DPREFIX=$HOME/.darling-xephyr
export DISPLAY=:99
export LIBGL_ALWAYS_SOFTWARE=true
export GALLIUM_DRIVER=llvmpipe
export MESA_LOADER_DRIVER_OVERRIDE=llvmpipe
export LIBGL_DRI3_DISABLE=true
```

For visible GUI stages, start Xephyr and a window manager separately, for
example `Xephyr :99` and `openbox` using `DISPLAY=:99`.

## Staged validation order

1. Darling shell baseline.
2. Electron `run-as-node` checks.
3. Electron app startup without creating a `BrowserWindow`.
4. Electron app startup with a hidden `BrowserWindow`.
5. Electron app startup with a visible `BrowserWindow` under
   Xephyr/openbox/llvmpipe.
6. Codex.app last.

Codex.app should not be the first target because it combines Electron startup,
Chromium runtime behavior, application code, native modules, and GUI behavior.

## Run-as-node smoke harness

Supply a macOS Electron-compatible binary that already exists inside the Darling
prefix. The script does not download, vendor, or require Codex.app.

```sh
tools/electron-run-as-node-smoke.sh \
  '/Users/you/Downloads/electron-smoke/Electron.app/Contents/MacOS/Electron'
```

The harness runs:

- `darling shell echo darling-shell-ok`
- `ELECTRON_RUN_AS_NODE=1 <binary> -e "console.log(process.versions)"`
- `fs.readdirSync("/")`
- `setImmediate` / `setTimeout`
- an optional `worker_threads` probe

Use `--skip-worker` if the Electron build does not expose `worker_threads` or if
you are isolating earlier startup behavior. Use `--dry-run` or `--help` in Cloud
to validate script wiring without launching Darling or Electron.

If the supplied binary is absent inside the Darling prefix, the harness reports
`skipped/missing external binary` for Electron probes instead of treating that as
a destructive failure.

## Current loader/symbol findings

A local Electron v43 darwin-x64 test under Darling used
`~/Downloads/electron-smoke`. Before adding QuickLookUI, startup failed because
Darling lacked:

- `/System/Library/Frameworks/QuickLookUI.framework/Versions/A/QuickLookUI`
- Objective-C class symbol `_OBJC_CLASS_$_QLPreviewPanel`

Darling's concrete `QLPreviewPanel` implementation is owned by Quartz. The
QuickLookUI framework in this branch preserves the expected framework and public
header surface, declares `QLPreviewPanel` as the same `NSPanel` subclass exposed
by Quartz, links Quartz normally, and narrowly re-exports the Quartz-owned
Objective-C `QLPreviewPanel` class symbols. Quartz also provides minimal safe
compatibility methods: `+sharedPreviewPanelExists` returns `NO`,
`+sharedPreviewPanel` returns `nil`, and panel refresh selectors are no-ops.
QuickLookUI must not define another concrete `QLPreviewPanel` class, because
loading Quartz and QuickLookUI together would otherwise register the same
Objective-C class twice.

Local Electron v43 validation has progressed past the known strong loader
symbol blockers, including the CoreServices `NSUserActivity` two-level import.
The current local run-as-node result exits immediately before JavaScript entry
with status 1:

```text
PROBE_STATUS=1
ELAPSED_SECONDS=0
JS_ENTRY_COUNT=0
```

There is no remaining observed symbol-not-found dyld abort, Objective-C
unrecognized-selector exception, segmentation fault, or signal termination in
that local run. Cloud validation cannot claim Electron or Codex.app runtime
success. Local validation still must rebuild and reinstall the affected
frameworks, inspect the resulting Mach-O exports for both slices, confirm the
QuickLookUI/Quartz duplicate-class warning is gone, and rerun the Electron
run-as-node smoke harness.
