/*
 * UART.c
 *
 * Created: 9/17/2023 6:51:11 AM
 *  Author: Acer
 */ 

#include "UART.h"


void UART_Init(void)
{
	//Select baud rate 9600
	UBRRL = Baud_rate_9600;
	
	/*
	Bit 1 – U2X:?Double the USART Transmission Speed
	Writing this bit to one will reduce the divisor of the baud rate divider from 16 to 8 effectively doubling the
	transfer rate for asynchronous communication.
	*/
	UCSRA &= ~(1<<U2X);
	
	/*
	Bits 5:4 –?Parity Mode - UCSRC Register
	0 0 Disabled ---->(selected)
	0 1 Reserved
	1 0 Enabled, Even Parity
	1 1 Enabled, Odd Parity
	*/
	UCSRC &=~((1<<4) | (1<<5));
	
	//frame
	/*
	Bits 2:1 – UCSZn:?Character Size - USCRC
	The UCSZ1:0 bits combined with the UCSZ2 bit in UCSRB sets the number of data bits (Character Size)
	in a frame the Receiver and Transmitter use.
	
	UCSZ2 UCSZ1 UCSZ0 Character_Size
	  0		0	  0		   5-bit
	  0		0	  1		   6-bit
	  0		1	  0		   7-bit
	  0		1	  1		   8-bit ---->(selected)
	  1		1	  1		   9-bit
	*/
	UCSRC |= ((1<<UCSZ0) | (1<<UCSZ1));
	
	
	//Enable check empty interrupt and receiver complete interrupt
	//UCSRB |=( (1<<Empty_Interrupt) | (1<<RX_Interrupt));
	
	//Enable Transmit and receive
	UCSRB |= ((1<<TX_En) | (1<<RX_En));
}

void UART_Transmit(uint8_t data)
{
	/*
	 Bit 5 – UDRE: USART Data Register Empty - UCSRA
	 The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. If UDRE is
	 one, the buffer is empty, and therefore ready to be written. The UDRE Flag can generate a Data
	 Register empty Interrupt (see description of the UDRIE bit).
	 UDRE is set after a reset to indicate that the transmitter is ready
	*/
	while( ( (UCSRA>>5)&1 ) == 0);
	
	//Send the data
	 UDR = (uint8_t)data;
}

uint8_t UART_Receive(void)
{
	/*
	Bit 7 – RXC: USART Receive Complete -UCSRA
	This flag bit is set when there are unread data in the receive buffer and cleared when the receive
	buffer is empty (that is, does not contain any unread data). If the receiver is disabled, the receive
	buffer will be flushed and consequently the RXC bit will become zero
	*/
	while( ( (UCSRA>>7)&1 ) == 0);
	
	//Return the data from buffer
	return UDR;	
}


void UART_String_Transmit(char *str)
{
	uint8_t i;
	for(i=0 ; (str[i]!='\0') && (i<25); i++)
	{
		UART_Transmit(str[i]);
	}
}

void UART_String_Receive(char* buffer)
{
	char i=-1;
do 
{
	i++;
	buffer[i]=UART_Receive();
} while ((buffer[i]!='\r') && (i<25));
	
	buffer[i] = '\0';
}

void UART_Number_Transmit(uint32_t num)
{
	uint8_t *ptr = &num;
	
	UART_Transmit(ptr[0]);
	UART_Transmit(ptr[1]);
	UART_Transmit(ptr[2]);
	UART_Transmit(ptr[3]);
}

uint32_t UART_Number_Receive(void)
{
	uint32_t num;
	uint8_t *ptr = &num;
	
	ptr[0] = UART_Receive();
	ptr[1] = UART_Receive();
	ptr[2] = UART_Receive();
	ptr[3] = UART_Receive();
	
	return num;
}

