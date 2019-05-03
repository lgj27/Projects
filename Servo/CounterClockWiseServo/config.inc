#include <avr/io.h>

#define SERVO_PIN     1
#define SERVO_PORT    _(PORTB)
#define SERVO_DIR     _(DDRB)

// include this line to avoid SFR_REG issues
#define _(s)    _SFR_IO_ADDR(s)
