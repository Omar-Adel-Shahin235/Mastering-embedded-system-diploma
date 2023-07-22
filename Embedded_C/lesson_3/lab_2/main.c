
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define RRC_base 0x40021000
#define GPIO_base 0x40010800

#define RCC_APB2ENR   *((volatile uint32_t *)(RRC_base + 0x18))
#define GPIO_CRH      *((volatile uint32_t *)(GPIO_base + 0x04))
#define GPIO_ODR      *((volatile uint32_t *)(GPIO_base + 0x0C))

unsigned char arr[3]={1,2,3};
unsigned char const arr1[3]={1,2,3};
unsigned char arr2[3];


int main(void)
{

	int i;

	RCC_APB2ENR |=(1<<2);

	GPIO_CRH &=0xff0fffff;
	GPIO_CRH |=0x00200000;


while (1){
	GPIO_ODR |=(1<<13);  //set bit 13

	for(i=0;i<500;i++);

	GPIO_ODR &=~(1<<13); //clear bit 13

	for(i=0;i<500;i++);
}

	return 0;
}
