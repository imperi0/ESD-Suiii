#include <LPC17xx.h>

// PORT 0, PIN 4 TO 11

int main() {
	
	unsigned int i;
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR = (0xFF << 4);
	
	while(1){
		
		for(i=0; i<8; i++){
			LPC_GPIO0->FIOSET = (0x01 << (4+i));
		}
		for(i=0; i<8; i++){
			LPC_GPIO0->FIOCLR = (0x01 << (4+i));
		}
		
	}
	
	return 0;
}