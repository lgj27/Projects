#include "config.inc"
#include <avr/io.h>

    .section    .text
    .global     delay

delay:
        ldi     r25, 255
2:      ldi     r26, 255
1:      dec     r26
        brne    1b
        dec     r25
        brne    2b
        ret
