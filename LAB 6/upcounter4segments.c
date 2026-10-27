/*#include <LPC17xx.h>

unsigned char seven_seg[] = {
    0x3F, 0x06, 0x5B, 0x4F,
    0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C,
    0x39, 0x5E, 0x79, 0x71
};

void delay(void)
{
    volatile unsigned int i;
    for (i = 0; i < 10000; i++);
}

int main(void)
{
    LPC_PINCON->PINSEL0 &= ~(0xFFFF << 8);
    LPC_PINCON->PINSEL3 &= ~(0xFF << 14);

    LPC_GPIO0->FIODIR |= (0xFF << 4);
    LPC_GPIO1->FIODIR |= (0x0F << 23);

    while (1)
    {
        LPC_GPIO1->FIOPIN = (1 << 23);
        LPC_GPIO0->FIOPIN = (unsigned int)seven_seg[1] << 4;
        delay();

        LPC_GPIO1->FIOPIN = (2 << 23);
        LPC_GPIO0->FIOPIN = (unsigned int)seven_seg[2] << 4;
        delay();

        LPC_GPIO1->FIOPIN = (4 << 23);
        LPC_GPIO0->FIOPIN = (unsigned int)seven_seg[3] << 4;
        delay();

        LPC_GPIO1->FIOPIN = (8 << 23);
        LPC_GPIO0->FIOPIN = (unsigned int)seven_seg[4] << 4;
        delay();
    }
}
*/


#include <LPC17xx.h>

#define SEG_MASK       (0xFFU << 4)   // P0.4–P0.11
#define DIGIT_SEL_MASK (0x0FU << 23)  // P1.23–P1.26

unsigned char seven_seg[10] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F   // 9
};

unsigned int dig[4]={0,1,2,3};

unsigned int digit;
volatile unsigned int j, i,k;

int main(void)
{
    SystemInit();
    SystemCoreClockUpdate();

    /*
     * CNA data lines:
     * P0.4–P0.11 as GPIO outputs
     */
    LPC_PINCON->PINSEL0 &= ~(0xFFFFU << 8);
    LPC_GPIO0->FIODIR |= SEG_MASK;

    /*
     * CNB digit-selection lines:
     * P1.23–P1.26 as GPIO outputs
     */
    LPC_PINCON->PINSEL3 &= ~(0xFFU << 14);
    LPC_GPIO1->FIODIR |= DIGIT_SEL_MASK;
    /*
     * Select the first digit.
     * Selection value 0 means all four control bits are LOW.
     */
    LPC_GPIO1->FIOCLR = DIGIT_SEL_MASK;

    /*while (1)
    {
					for(i=0; i<4; i++){
					LPC_GPIO1->FIOPIN = (i << 23);
					
							// Clear previous segment pattern
							// LPC_GPIO0->FIOCLR = SEG_MASK;

							// Display new pattern
							LPC_GPIO0->FIOPIN =
									((unsigned int)seven_seg[digit] << 4);

							for (j = 0; j < 1000000; j++);
					}
					
    }*/
		/*
		while (1)
{
    for (i = 0; i < 4; i++)
    {
        LPC_GPIO1->FIOPIN = (i << 23);

        LPC_GPIO0->FIOPIN =
            ((unsigned int)seven_seg[dig[i]] << 4);

        for (j = 0; j < 5000; j++);
    }
}*/
	while (1)
{
    for (digit = 0; digit < 10000; digit++)
    {
        dig[3] = digit / 1000;
        dig[2] = (digit / 100) % 10;
        dig[1] = (digit / 10) % 10;
        dig[0] = digit % 10;

        // Refresh all four SSDs repeatedly
        for (k = 0; k < 100; k++)
        {
            for (i = 0; i < 4; i++)
            {
                LPC_GPIO1->FIOPIN = (i << 23);

                LPC_GPIO0->FIOPIN =
                    ((unsigned int)seven_seg[dig[i]] << 4);

                for (j = 0; j < 5000; j++);
            }
        }
    }
}
}
