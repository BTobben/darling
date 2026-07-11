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

The QuickLookUI framework in this branch is only a compatibility shim. It
exports `QLPreviewPanel` and no-ops common panel refresh methods; it does not
implement real QuickLook preview UI.

After a local QuickLookUI shim was installed into the Darling prefix, Electron
advanced to the next observed blocker:

```text
dyld: Symbol not found: _OBJC_CLASS_$_NSConstantIntegerNumber
  Referenced from: ReactiveObjC.framework/ReactiveObjC
  Expected in: Foundation.framework/Versions/C/Foundation
```

`NSConstantIntegerNumber` belongs in Foundation. This branch routes the
`src/external/foundation` submodule to the `BTobben/darling-foundation` fork and
pins it to the `codex/implement-nsconstantintegernumber-compatibility-class`
branch commit that adds a minimal private `NSConstantIntegerNumber : NSNumber`
compatibility class in Foundation's `src/NSNumber.m`.

Cloud validation cannot claim Electron runtime success. Local validation still
must rebuild/reinstall Foundation, verify that the Foundation binary exports
`_OBJC_CLASS_$_NSConstantIntegerNumber`, and rerun the Electron run-as-node
smoke harness.
