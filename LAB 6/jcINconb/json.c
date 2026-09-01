#include <LPC17xx.h>

// PORT 0, PIN 4 TO 11

int main() {
	
	volatile unsigned int i, j;
	LPC_PINCON->PINSEL3 &= 0;
	LPC_PINCON->PINSEL4 &= 0;
	LPC_GPIO1->FIODIR = (0xF << 23);
	LPC_GPIO2->FIODIR = (0xF << 10);
	
	while(1){
		
		for(i=0; i<4; i++){
			LPC_GPIO1->FIOSET = (0x01 << (23+i));
			for(j=0; j<1000000; j++);
		}
		for(i=0; i<4; i++){
			LPC_GPIO2->FIOSET = (0x01 << (10+i));
			for(j=0; j<1000000; j++);
		}
		for(i=0; i<4; i++){
			LPC_GPIO1->FIOCLR = (0x01 << (23+i));
			for(j=0; j<1000000; j++);
		}
		for(i=0; i<4; i++){
			LPC_GPIO2->FIOCLR = (0x01 << (10+i));
			for(j=0; j<1000000; j++);
		}
		
	}
	
	return 0;
}