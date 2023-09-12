/*
 * DIO.c
 *
 * Created: 9/12/2023 6:58:52 AM
 *  Author: Acer
 */ 

#include "DIO.h"


void MCAL_Dio_pinDirection(PortConfig Port_Config ,uint8_t Pin_number ,uint8_t Statues)
{
	
	switch(Statues)
	{
		case Input_Statues:
			switch(Port_Config)
			{
				case 0:
				DDRA &= ~(Pin_number);
				break;
				
				case 1:
				DDRB &= ~(Pin_number);
				break;

				case 2:
				DDRC &= ~(Pin_number);
				break;

				case 3:
				DDRD &= ~(Pin_number);
				break;
			}
			break;
		
		case Output_Statues:
		
		switch(Port_Config)
		{
			case 0:
			DDRA |= (Pin_number);
			break;
			
			case 1:
			DDRB |= (Pin_number);
			break;

			case 2:
			DDRC |= (Pin_number);
			break;

			case 3:
			DDRD |= (Pin_number);
			break;
		}
		break;	
	}
		
}

//**********************************************
//==============================================
//**********************************************
void MCAL_Dio_PortDirection(PortConfig Port_Config ,uint8_t Statues)
{
	switch(Statues)
	{
		case Input_Statues:
		switch(Port_Config)
		{
			case 0:
			DDRA &= ~(0xFF);
			break;
			
			case 1:
			DDRB &= ~(0xFF);
			break;

			case 2:
			DDRC &= ~(0xFF);
			break;

			case 3:
			DDRD &= ~(0xFF);
			break;
		}
		break;
		
		case Output_Statues:
		
		switch(Port_Config)
		{
			case 0:
			DDRA |= (0xFF);
			break;
			
			case 1:
			DDRB |= (0xFF);
			break;

			case 2:
			DDRC |= (0xFF);
			break;

			case 3:
			DDRD |= (0xFF);
			break;
		}
		break;
	}
}


//**********************************************
//==============================================
//**********************************************

void MCAL_Dio_pinWrite(PortConfig Port_Config , uint8_t Pin_number , uint8_t value)
{
	switch(value)
	{
		case 0:
		switch(Port_Config)
		{
			case 0:
			PORTA &= ~(Pin_number);
			break;
			
			case 1:
			PORTB &= ~(Pin_number);
			break;

			case 2:
			PORTC &= ~(Pin_number);
			break;

			case 3:
			PORTD &= ~(Pin_number);
			break;
		}
		break;
		
		case 1:
		
		switch(Port_Config)
		{
			case 0:
			PORTA |= (Pin_number);
			break;
			
			case 1:
			PORTB |= (Pin_number);
			break;

			case 2:
			PORTC |= (Pin_number);
			break;

			case 3:
			PORTD |= (Pin_number);
			break;
		}
		break;
	}
}


//**********************************************
//==============================================
//**********************************************


void MCAL_Dio_PortWrite(PortConfig Port_Config , uint8_t value)
{
		switch(Port_Config)
		{
			case 0:
			PORTA = (value);
			break;
			
			case 1:
			PORTB |= (value);
			break;

			case 2:
			PORTC |= (value);
			break;

			case 3:
			PORTD |= (value);
			break;
		}
}

//**********************************************
//==============================================
//**********************************************


uint8_t MCAL_Dio_pinRead(PortConfig Port_Config , uint8_t Pin_number)
{
	uint8_t val=0;
	
	switch(Port_Config)
	{
		case 0:
		val = (PINA & Pin_number);
		break;
		
		case 1:
		val = (PINB & Pin_number);
		break;

		case 2:
		val = (PINC & Pin_number);
		break;

		case 3:
		val = (PIND & Pin_number);
		break;
	}
	
	if(val>0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//**********************************************
//==============================================
//**********************************************

uint8_t MCAL_Dio_PortRead(PortConfig Port_Config)
{
	uint8_t val=0;
	switch(Port_Config)
	{
		case 0:
		val = (PINA);
		break;
		
		case 1:
		val = (PINB);
		break;

		case 2:
		val = (PINC);
		break;

		case 3:
		val = (PIND);
		break;
	}
	
		return val;
}


//**********************************************
//==============================================
//**********************************************


void MCAL_Dio_PinToggle(PortConfig Port_Config , uint8_t Pin_number)
{
	switch(Port_Config)
	{
		case 0:
		PORTA ^= (Pin_number);
		break;
		
		case 1:
		PORTB ^= (Pin_number);
		break;

		case 2:
		PORTC ^= (Pin_number);
		break;

		case 3:
		PORTD ^= (Pin_number);
		break;
	}

}


//**********************************************
//==============================================
//**********************************************


void MCAL_Dio_Pin_Input_PullUp(PortConfig Port_Config , uint8_t Pin_number)
{
	MCAL_Dio_pinWrite(Port_Config , Pin_number , 1);
}



/*
int i;
switch(Statues)
{
	case Input_Statues:
	for(i=0 ; i<4 ; i++)
	{
		if(Port_Config == i)
		{
			(*((volatile unsigned char*)(Port_base-(3*i)))) &= ~(Pin_number);
			break;
		}
	}
	break;
	
	case Output_Statues:
	for(i=0 ; i<4 ; i++)
	{
		if(Port_Config == i)
		{
			(*((volatile unsigned char*)(Port_base-(3*i)))) |= (Pin_number);
			break;
		}
	}
	break;
}
*/