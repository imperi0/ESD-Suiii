#include <LPC17xx.h>


unsigned int i, dig=1234, number, row, col, x, j;

unsigned int choose[4];
unsigned char array_dec[4][4] ={{0x3F, 0x06, 0x5B, 0x4F}, {0x66, 0x6D, 0x7D, 0x07}, {0x7F, 0x6F, 0x77, 0x7A}, {0x39, 0x5F, 0x79, 0x71}};

	
void delay(void){
	unsigned int j;
  for(j=0; j<10000; j++);
}
	
void display(){
	// number=dig;
	// choose[0]=number%10; number=number/10;
	// choose[1]=number%10; number=number/10;
	// choose[2]=number%10; number=number/10;
	// choose[3]=number%10;
		
	for(i=0; i<4; i++){
		LPC_GPIO0->FIOPIN=((i<<15)|(dig<<4));
		for(j = 0; j < 500; j++);
	}
	delay();
	//dig++;
	//if(dig==10000){
	// dig=0;
	// }
}

void scan(){
	x=(LPC_GPIO1->FIOPIN & 0xF<<23)>>23;
	if(x){
		if(x==1){
			col=0;
		} else if(x==2){
			col=1;
		} else if(x==4){
			col=2;
		} else if(x==8){
			col=3;
		}
		x=0;
	}
}


int main(){

	LPC_PINCON->PINSEL0=0;
	LPC_GPIO0->FIODIR=(0xFF<<4) | (0xF<<15);

	LPC_GPIO2->FIODIR=(0xF<<10); // ROW
	
	while(1){
		for(row=0 ; row<4; row++){
			LPC_GPIO2->FIOPIN=(1<<(row+10));
			scan();
			if(!x){
				dig=array_dec[row][col];
			}
			display();
		}
	}
}
