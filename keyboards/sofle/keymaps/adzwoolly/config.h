// Copyright 2026 adzwoolly
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// LOWER + RAISE = ADJUST. Must match the layer enum in keymap.c
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 3

// Send layer and Caps Lock state to the right half so its screen can show them
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
