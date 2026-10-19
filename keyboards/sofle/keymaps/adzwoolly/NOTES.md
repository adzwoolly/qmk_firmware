# adzwoolly Sofle keymap – notes

## Hardware
- Sofle rev1, two **Elite-C** controllers (Atmel DFU bootloader, not Caterina). `rules.mk` sets `BOOTLOADER = atmel-dfu`.
- USB plugs into the **left** half (left is master).
- Two 128x32 OLEDs. The left one is unreliable (works ~2% of the time), probably hardware. Both screens show the same status so the right one can always show the layer.
- No per-key RGB LEDs. RGB is not enabled.
- Bootmagic is on: hold the top-left key while plugging in to enter the bootloader and clear EEPROM.

## Layout
- OS is set to **UK QWERTY**. Dvorak is done in the firmware. On UK, `KC_BSLS` types `#` and `KC_NUBS` types `\`; Shift+2 = `"`, Shift+3 = `£`, Shift+' = `@`.
- Layers: DVORAK (base), LOWER (F-keys, numpad on the right, openers `( [ {` down the left half's inner column and closers `) ] }` down the right half's inner column, plain keys), RAISE (arrows in a WASD shape on the right), ADJUST = LOWER + RAISE (media on the right, `QK_BOOT` top-left).
- Numpad uses the normal number keycodes (`KC_1`, not `KC_P1`), so Shift gives the symbols above them.
- The base layer is fixed. There are no persistent default-layer switch keys (`PDF()` / `set_single_persistent_default_layer`). The old firmware got stuck on a saved QWERTY default layer, and that's the reason.
- Left dial: volume, press = mute. Right dial: scroll, press = middle click.
- Firmware size 20622/28672 bytes (71%).
- LOWER also has `/ * - +`, `\ | &` (`\` is `KC_NUBS` and `|` is `S(KC_NUBS)`, since `KC_PIPE` types `~` on UK) and `= #` on the left, `- +` on the right and F12 on the right of row 2; `0` is on the right RCtl thumb. RAISE has Ctrl+Left/Right (word jump) and Home/End on the bottom row.
- `/` and `?` (Shift+`/`) are on the base layer's right outer column.

## History
- The old firmware (the original Dvorak build, made on another PC) was never committed and is lost. The Elite-C bootloader is read-protected, so it couldn't be dumped, and EEPROM writes were refused too.
- This keymap was rewritten from scratch in Oct 2026 against current QMK.

## Install
1. Compile `qmk compile -kb sofle/rev1 -km adzwoolly`
2. Install using QMK Toolbox with path `\\wsl.localhost\Ubuntu\home\adzwoolly\code\qmk_firmware\sofle_rev1_adzwoolly.hex`

## To check
- [x] Compiled OK (Oct 2026). Build: `qmk compile -kb sofle/rev1 -km adzwoolly`
- [ ] Right screen orientation: if it's upside down, swap `OLED_ROTATION_90` for `OLED_ROTATION_270` in `oled_init_user`.
- [ ] Dial direction: if either dial runs backwards, swap the `clockwise` branches in `encoder_update_user`.
- [x] OS is UK QWERTY (confirmed). `KC_BSLS` types `#`, `KC_NUBS` types `\`; placement of `\`, `#`, `-`, `=` still to decide.
- [ ] Flash both halves (Elite-C: press reset once, then flash with QMK Toolbox from Windows).
