; SERVO Movement 

#include "config.inc"

        .section .text
        .global     main
        .extern     delay        
        .org        0x0000

main:
        ; set up the stack
        ldi         r28, (RAMEND & 0x00ff)
        ldi         r29, (RAMEND >> 8)
        out         _(SPH), r29
        out         _(SPL), r28

        ; initilaize the chip for movement
        call        init      

        ; enter the servo loop
1:      call        toggle
        call        delay
	call        toggle
	call        delay
	call        toggle
	call        delay
        rjmp        1b



init:   eor         r1, r1                  ; zero out the r1 register
        out         _(SREG), r1               ; initialize the status reg
        ldi         r24, 0x80
        sts         CLKPR, r24              ; allow access to clock setup
        sts         CLKPR, r1               ; run at full speed
        
        ; set up the SERVO port
        sbi         SERVO_DIR, SERVO_PIN        ; set SERVO pin to output
        cbi         SERVO_PORT, SERVO_PIN       ; start with the SERVO off
        ret

toggle:
        in          r24, SERVO_PORT           ; get current bits
        ldi         r25, (1 << SERVO_PIN)     ; SERVO is pin 1
        eor         r24, r25                ; flip the bit
        out         SERVO_PORT, r24           ; write the bits back
        ret
