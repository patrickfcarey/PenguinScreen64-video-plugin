# PenguinScreen64-video-plugin

The video plugin for **PenguinScreen64** — a fork of
[GLideN64](https://github.com/gonetz/GLideN64) extended with a per-eye VR
render path. Paired with the PenguinScreen64 core, profiled games render with
true dual-view stereoscopic depth; on its own it behaves as the excellent
standard GLideN64 plugin it is built on.

> **Status: early source release.** Builds like upstream GLideN64. Binary
> packages ship bundled with the PenguinScreen64 core releases.

## What the fork adds

- A stereo render path driven by the core's VR bridge (per-eye view offsets
  computed from the per-game profile's convergence/separation).
- Config keys for the VR pipeline, resolved through the standard GLideN64
  config system — no behaviour change when VR is off.

## License

GPL-2.0-or-later, inherited from GLideN64 (see [LICENSE](LICENSE)).

## Credits

GLideN64 is the work of Sergey Lipskiy and contributors, standing on the
Glide64/glN64 lineage — all rendering credit belongs there. This fork adds
only the VR path.
