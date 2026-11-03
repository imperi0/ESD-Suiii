#include <LPC17xx.h>

unsigned long x,y,z;

void ADC_IRQHandler(void);

int main(void){
	
	LPC_PINCON->PINSEL3=0x3<<28 | 0x3<<30;
	LPC_SC->PCONP=1<<12;
	LPC_ADC->ADCR=1<<4 | 1<<5 | 1<<16 | 1<<21;
	LPC_ADC->ADINTEN=1<<4 | 1<<5;
	NVIC_EnableIRQ(ADC_IRQn);
	
	while(1){
		
	}
	
}

void ADC_IRQHandler(void){

	x=LPC_ADC->ADDR4;
	x=x>>4;
	x=x&0xFFF;
	
	y=LPC_ADC->ADDR5;
	y=y>>4;
	y=y&0xFFF;
	
	z=x-y;
}
