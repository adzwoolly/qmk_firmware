# adzwoolly Sofle keymap – notes

## Hardware
- Sofle rev1, two **Elite-C** controllers (Atmel DFU bootloader, not Caterina). `rules.mk` sets `BOOTLOADER = atmel-dfu`.
- USB plugs into the **left** half (left is master).
- Two 128x32 OLEDs. The left one is unreliable (works ~2% of the time), probably hardware. Both screens show the same status so the right one can always show the layer.
- No per-key RGB LEDs. RGB is not enabled.
- Bootmagic is on: hold the top-left key while plugging in to enter the bootloader and clear EEPROM.

## Layout
- OS is set to **QWERTY**. Dvorak is done in the firmware.
- Layers: DVORAK (base), LOWER (F-keys, `[ ] \ =` on the left, numpad on the right), RAISE (arrows in a WASD shape on the right), ADJUST = LOWER + RAISE (media on the right, `QK_BOOT` top-left).
- Numpad uses the normal number keycodes (`KC_1`, not `KC_P1`), so Shift gives the symbols above them.
- The base layer is fixed. There are no persistent default-layer switch keys (`PDF()` / `set_single_persistent_default_layer`). The old firmware got stuck on a saved QWERTY default layer, and that's the reason.
- Left dial: volume, press = mute. Right dial: scroll, press = middle click.

## History
- The old firmware (the original Dvorak build, made on another PC) was never committed and is lost. The Elite-C bootloader is read-protected, so it couldn't be dumped, and EEPROM writes were refused too.
- This keymap was rewritten from scratch in Oct 2026 against current QMK.

## To check
- [ ] **Not compiled yet.** Build: `qmk compile -kb sofle/rev1 -km adzwoolly`
- [ ] Right screen orientation: if it's upside down, swap `OLED_ROTATION_90` for `OLED_ROTATION_270` in `oled_init_user`.
- [ ] Dial direction: if either dial runs backwards, swap the `clockwise` branches in `encoder_update_user`.
- [ ] Whether the OS is UK or US QWERTY. Symbol keys (`'`, `` ` ``, `\`, `#`) differ between the two.
- [ ] Flash both halves (Elite-C: press reset once, then flash with QMK Toolbox from Windows).
