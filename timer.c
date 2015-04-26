#include <msp430g2553.h>

#define LED BIT6 //Using P1.6 LED 

Forward declarations
void init(void);

void main(void)
{
	init();

	while(1)
	{

	}
}

void init(void)
{
	WDTCTL = WDTPW + WDTHOLD; //Stop watchdog timer
	
	P1DIR = LED;
	P1OUT = LED;

	TA0CCTL0 = CCIE; //Enable interrupt
	TA0CCTL1 = CCIE;
	TA0CCR1 = 6000-1; //Duty cycle

	TA0CTL = TASSEL_2 + MC_2; //SMCLK, up mode

	__enable_interrupt(); //set GIE in SR
	_BIS_SR(CPUOFF + GIE); //Enter LPM0 with interrupt
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void timerA0(void)
{
	timer = (timer + 1) % 8;
	if(timer == 0)
		P1OUT ^= LED;
}
