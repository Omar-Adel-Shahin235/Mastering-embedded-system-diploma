#include "UART.h"

unsigned char str[100] = "Embedded system:omar";
unsigned char const str2[100]="my name is omar";

void main(void)
{	
	Uart_send_string(str);	
}
