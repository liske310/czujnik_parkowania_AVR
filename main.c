#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "HC-SR04-lib/usound.h"

void init_LED();

uint8_t CAR = 0;

// Main:
int main(void)
{
	init_LED();
	usound_init();
	while(1)
	{
		if(readDistance() < 10){
			if(CAR ==0){
				PORTB &= ~(1<<PB1); // ON
				CAR = 1;
				_delay_ms(5000);
				PORTB |= (1<<PB1); //OFF
			}
		}
		else{
			PORTB |= (1<<PB1); //OFF
			CAR=0;
		}
		_delay_ms(200);
	}
}

void init_LED(){
    DDRB |= (1<<PB1);
}
