#ifndef _COMMON_DVI_PIN_CONFIGS_H
#define _COMMON_DVI_PIN_CONFIGS_H
// This file defines the TMDS pair layouts on a handful of boards I have been
// developing on. It's not a particularly important file -- just saves some
// copy + paste.
#include "dvi_serialiser.h"

// Pico DVI Sock (small hat on the bottom) which solders to the end of a Pico

// It gave a compiler error because config defined after the macro that uses it.
// MOVED HERE
static const struct dvi_serialiser_cfg pico_sock_cfg = {
        .pio = pio0,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {36, 34, 32},
        .pins_clk = 38,
        .invert_diffpairs = false
};


// The macro DVI_DEFAULT_SERIAL_CONFIG expands to pico_sock_cfg (a variable name),
// but when used like .pio, the preprocessor gets it wrong.
// change the macro to reference the address and update the usage. 
#ifndef DVI_DEFAULT_SERIAL_CONFIG
#define DVI_DEFAULT_SERIAL_CONFIG (&pico_sock_cfg)
#endif
#ifndef DVI_DEFAULT_PIO_INST
#define DVI_DEFAULT_PIO_INST pio0
#endif

// Rest of the definitions...
// Legacy pin mapping for Rev A PicoDVI boards
static const struct dvi_serialiser_cfg picodvi_reva_dvi_cfg = {
        .pio = DVI_DEFAULT_PIO_INST,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {24, 26, 28},
        .pins_clk = 22,
        .invert_diffpairs = true
};

static const struct dvi_serialiser_cfg amy_dvi_cfg = {
        .pio = DVI_DEFAULT_PIO_INST,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {14, 16, 18},
        .pins_clk = 12,
        .invert_diffpairs = true
};

static const struct dvi_serialiser_cfg picodvi_dvi_cfg = {
        .pio = DVI_DEFAULT_PIO_INST,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {10, 12, 14},
        .pins_clk = 8,
        .invert_diffpairs = true
};

static const struct dvi_serialiser_cfg picodvi_pmod0_cfg = {
        .pio = DVI_DEFAULT_PIO_INST,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {2, 4, 0},
        .pins_clk = 6,
        .invert_diffpairs = false
};

static const struct dvi_serialiser_cfg micromod_cfg = {
        .pio = DVI_DEFAULT_PIO_INST,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {18, 20, 22},
        .pins_clk = 16,
        .invert_diffpairs = true
};

static const struct dvi_serialiser_cfg pimoroni_demo_hdmi_cfg = {
        .pio = DVI_DEFAULT_PIO_INST,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {8, 10, 12},
        .pins_clk = 6,
        .invert_diffpairs = true
};

static const struct dvi_serialiser_cfg not_hdmi_featherwing_cfg = {
        .pio = pio0,
        .sm_tmds = {0, 1, 2},
        .pins_tmds = {11, 9, 7},
        .pins_clk = 24,
        .invert_diffpairs = true
};

#endif
