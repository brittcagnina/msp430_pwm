#include <msp430g2553.h>
 
// Connect the servo SIGNAL wire to P1.2 through a 1K resistor.

#define MCU_CLOCK	1000000
#define PWM_FREQUENCY	46	// In Hertz, ideally 50Hz.
#define SERVO_MIN	650	// The minimum duty cycle for this servo
#define SERVO_MAX	2700	// The maximum duty cycle
 
unsigned int PWM_Period	= (MCU_CLOCK / PWM_FREQUENCY);	// PWM Period
unsigned int PWM_Duty	= SERVO_MIN;
 
void main (void){
	WDTCTL = WDTPW | WDTHOLD;
	TACCTL1 = OUTMOD_7;            // TACCR1 reset/set
	TACTL	= TASSEL_2 + MC_1;     // SMCLK, upmode
	TACCR0	= PWM_Period - 1;      // PWM Period
	TACCR1	= PWM_Duty;            // TACCR1 PWM Duty Cycle
	P1DIR	|= BIT2;               // P1.2 = output
	P1SEL	|= BIT2;               // P1.2 = TA1 output

	// Main loop
	while (1) {

   	}
}
