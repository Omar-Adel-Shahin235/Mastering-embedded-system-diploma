/*
 * UART.h
 *
 * Created: 9/17/2023 6:51:24 AM
 *  Author: Acer
 */ 


#ifndef UART_H_
#define UART_H_

#include "Register_map.h"

//Double the UART Speed
#define U2X              1

//Enable UART Operations
#define TX_En            3
#define RX_En            4

//Enable interrupt Operations
#define RX_Interrupt            7
#define TX_Interrupt			6	
#define Empty_Interrupt			5

//Character size
#define UCSZ0			 1
#define UCSZ1			 2
#define UCSZ2			 2

#define Baud_rate_9600   51



void UART_Init(void);

void UART_Transmit(uint8_t data);

uint8_t UART_Receive(void);

void UART_String_Transmit(char *str);

void UART_String_Receive(char* buffer);

void UART_Number_Transmit(uint32_t num);

uint32_t UART_Number_Receive(void);





#endif /* UART_H_ */