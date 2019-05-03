; delay2.S
;   off 1 second delay
#include <avr/io.h>

        .section        .text
        .global         delay2


delay2:
        ldi         r19, 160             ; outer loop
1:
        ldi         r20, 160            ; middle loop
2:      
        ldi         r21, 160            ; inner lool
3:
        dec         r21
        brne        3b                  ; inner loop
        dec         r20
        brne        2b                  ; middle loop
        dec         r19
        brne        1b                  ; outer loop
        ret
