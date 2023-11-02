/*
 * ADC.c
 *
 * Created: 11/2/2023 8:33:42 AM
 *  Author: Acer
 */ 

#include "ADC.h"

void ADC_init(ADV_Vref_type Vref ,ADC_Prescaler_type Prescaler)
{
	switch(Vref)
	{
		case VREF_AREF:
		ADMUX &= ~((1<<6) | (1<<7));
		break;
		
		case VREF_AVCC:
		ADMUX |= (1<<6);
		ADMUX &= ~(1<<7);
		break;
		
		case VREF_256:
		ADMUX |= ((1<<6) | (1<<7)) ;
		break;
	}
	
	//prescaler
	
	//keep bits
	ADCSRA &= 0xF8 ;   //1111 1000
	ADCSRA |= Prescaler ;
	
	//enable ADC
	ADCSRA |= (1<<ADEN);
}

uint16_t ADC_Read(ADC_Channel_type channel)
{
	//Keep pits
	ADMUX &= 0xE0;    //1110 0000
	ADMUX |= channel;
	
	ADCSRA |= (1<<ADSC);
	
	while(!(ADCSRA>>ADIF)&1);
	
//	ADCSRA |= (1<<ADIF);
	
	return ADC;
	
}