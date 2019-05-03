#include "config.inc"
#include <avr/io.h>

    .section    .text
    .global     delay

delay:

        ldi      r26, 255
1:      dec      r26
        brne     1b
        ret
