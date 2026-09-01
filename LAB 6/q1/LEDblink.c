#include <LPC17xx.h>
#include <stdio.h>

// PORT 0, PIN 4 TO 11

int main() {
	
	unsigned int i;
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR = (0xFF << 4);
	
	while(1){
		
		LPC_GPIO0->FIOSET = (0xFF << 4);
		for(i=0; i<1000; i++){
		}
		
		LPC_GPIO0->FIOCLR = (0xFF << 4);
		for(i=0; i<1000; i++){
		}
		
	}
	
	return 0;
}