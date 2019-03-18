// Emisar FET+13+1 config options for Anduril
#include "hwdef-Emisar_D18.h"

// front-facing aux LEDs
#define USE_INDICATOR_LED
//#define USE_INDICATOR_LED_WHILE_RAMPING
// enable blinking indicator LED while off
#define TICK_DURING_STANDBY
#define STANDBY_TICK_SPEED 3  // every 0.128 s
#define USE_FANCIER_BLINKING_INDICATOR
// off mode: low (1)
// lockout: blinking (3)
#define INDICATOR_LED_DEFAULT_MODE ((3<<2) + 1)

// Emisar wanted a shortcut to this
#define USE_TENCLICK_THERMAL_CONFIG


// level_calc.py ninth 3 150 7135 1 2.0 130.2 7135 1 1 2203.62 FET 1 10 12000
// (designed to make 1x hit at level 55, and Nx hit at level 110)
#define RAMP_LENGTH 150
#define PWM1_LEVELS 1,1,2,2,3,3,4,5,5,6,7,8,9,10,11,13,14,15,17,19,21,22,25,27,29,32,35,38,41,44,48,52,56,60,65,70,76,81,87,94,101,108,116,124,133,142,152,163,174,185,198,211,225,239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0
#define PWM2_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,4,5,6,7,9,10,12,13,15,17,18,20,22,24,26,29,31,34,36,39,42,45,48,52,55,59,63,67,71,76,80,85,90,96,101,107,113,120,126,133,140,148,156,164,172,181,191,200,210,221,232,243,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0
#define PWM3_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,6,10,13,16,19,23,27,30,34,39,43,47,52,57,62,67,72,78,84,90,96,103,109,116,123,131,138,146,155,163,172,181,191,201,211,221,232,243,255
#define MAX_1x7135 55
#define MAX_Nx7135 110
#define HALFSPEED_LEVEL 16
#define QUARTERSPEED_LEVEL 5

// start at ~2000 lm after battery change, not ~150 lm (at Emisar's request)
#define DEFAULT_LEVEL MAX_Nx7135

// higher floor than default, and stop at highest regulated level
#define RAMP_DISCRETE_FLOOR 20
#define RAMP_DISCRETE_CEIL MAX_Nx7135
#define RAMP_DISCRETE_STEPS 7

// only blink at max regulated level and ceiling
#define BLINK_AT_RAMP_MIDDLE
#define BLINK_AT_RAMP_MIDDLE_1 MAX_Nx7135
#define BLINK_AT_RAMP_CEILING

// stop panicking at about ~30% power or ~3600 lm
#define THERM_FASTER_LEVEL 120
// optional, makes initial turbo step-down faster so first peak isn't as hot
#define THERM_HARD_TURBO_DROP
