/*
 * Memory_map.h
 *
 * Created: 9/5/2023 9:01:55 PM
 *  Author: Acer
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#define DDRA *((volatile unsigned char*)0x3A)
#define PORTA *((volatile unsigned char*)0x3B)

#define DDRB *((volatile unsigned char*)0x37)
#define PORTB *((volatile unsigned char*)0x38)
#define PINB *((volatile unsigned char*)0x36)

#define DDRC *((volatile unsigned char*)0x34)
#define PORTC *((volatile unsigned char*)0x35)
#define PINC *((volatile unsigned char*)0x33)

#define DDRD *((volatile unsigned char*)0x31)
#define PORTD *((volatile unsigned char*)0x32)
#define PIND *((volatile unsigned char*)0x30)


#endif /* MEMORY_MAP_H_ */