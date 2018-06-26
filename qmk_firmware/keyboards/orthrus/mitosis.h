#ifndef MITOSIS_H
#define MITOSIS_H

#include "quantum.h"
#include "matrix.h"
#include "backlight.h"
#include <stddef.h>

#define red_led_off   PORTF |= (1<<5)
#define red_led_on    PORTF &= ~(1<<5)
#define blu_led_off   PORTF |= (1<<4)
#define blu_led_on    PORTF &= ~(1<<4)
#define grn_led_off   PORTD |= (1<<1)
#define grn_led_on    PORTD &= ~(1<<1)

#define set_led_off     red_led_off; grn_led_off; blu_led_off
#define set_led_red     red_led_on;  grn_led_off; blu_led_off
#define set_led_blue    red_led_off; grn_led_off; blu_led_on
#define set_led_green   red_led_off; grn_led_on;  blu_led_off
#define set_led_yellow  red_led_on;  grn_led_on;  blu_led_off
#define set_led_magenta red_led_on;  grn_led_off; blu_led_on
#define set_led_cyan    red_led_off; grn_led_on;  blu_led_on
#define set_led_white   red_led_on;  grn_led_on;  blu_led_on

/*
#define LED_B 5
#define LED_R 6
#define LED_G 7

#define all_leds_off PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)

#define red_led_on   PORTF |= (1<<LED_R)
#define red_led_off  PORTF &= ~(1<<LED_R)
#define grn_led_on   PORTF |= (1<<LED_G)
#define grn_led_off  PORTF &= ~(1<<LED_G)
#define blu_led_on   PORTF |= (1<<LED_B)
#define blu_led_off  PORTF &= ~(1<<LED_B)

#define set_led_off     PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)
#define set_led_red     PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_G) | (1<<LED_R)
#define set_led_blue    PORTF = PORTF & ~(1<<LED_G) & ~(1<<LED_R) | (1<<LED_B)
#define set_led_green   PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_R) | (1<<LED_G)
#define set_led_yellow  PORTF = PORTF & ~(1<<LED_B) | (1<<LED_R) | (1<<LED_G)
#define set_led_magenta PORTF = PORTF & ~(1<<LED_G) | (1<<LED_R) | (1<<LED_B)
#define set_led_cyan    PORTF = PORTF & ~(1<<LED_R) | (1<<LED_B) | (1<<LED_G)
#define set_led_white   PORTF |= (1<<LED_B) | (1<<LED_R) | (1<<LED_G)
*/

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k11, k21, k31, k41, k51, k61,             k91, kA1, kB1, kC1, kD1, kE1, \
    k12, k22, k32, k42, k52, k62,             k92, kA2, kB2, kC2, kD2, kE2, \
    k13, k23, k33, k43, k53, k63,             k93, kA3, kB3, kC3, kD3, kE3, \
    k14, k24, k34, k44, k54, k64,             k94, kA4, kB4, kC4, kD4, kE4, \
                   k45, k55, k65, k75,   k85, k95, kA5, kB5                 \
) \
{ \
	{ k11,   k21,   k31,   k41, k51, k61, k91, kA1, kB1, kC1,   kD1,   kE1 }, \
	{ k12,   k22,   k32,   k42, k52, k62, k92, kA2, kB2, kC2,   kD2,   kE2 }, \
	{ k13,   k23,   k33,   k43, k53, k63, k93, kA3, kB3, kC3,   kD3,   kE3 }, \
	{ k14,   k24,   k34,   k44, k54, k64, k94, kA4, kB4, kC4,   kD4,   kE4 },  \
	{ KC_NO, KC_NO, k45,   k55, k65, k75, k85, k95, kA5, kB5,   KC_NO, KC_NO } \
}

#endif
