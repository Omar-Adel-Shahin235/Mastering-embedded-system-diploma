/*
 * DIO.h
 *
 * Created: 9/12/2023 7:12:01 AM
 *  Author: Acer
 */ 

#include "Register_map.h"
#include <stdint.h>


#ifndef DIO_H_
#define DIO_H_


typedef enum{
 PORT_A=0,        
 PORT_B  ,       
 PORT_C  ,        
 PORT_D 
}PortConfig;


//@ref Pin_define_number

#define Pin_0		0x01
#define Pin_1		0x02
#define Pin_2		0x04
#define Pin_3		0x08
#define Pin_4		0x10
#define Pin_5		0x20
#define Pin_6		0x40
#define Pin_7		0x80

//@ref Pin_define_Statues
#define Output_Statues		1
#define Input_Statues		0

//@ref Pin_Input_state_number

#define Enable_pull_up		1
#define Disable_pull_up     0


//API functions

void MCAL_Dio_pinDirection(PortConfig Port_Config ,uint8_t Pin_number ,uint8_t Statues);
void MCAL_Dio_PortDirection(PortConfig Port_Config ,uint8_t Statues);

void MCAL_Dio_pinWrite(PortConfig Port_Config , uint8_t Pin_number , uint8_t value);
void MCAL_Dio_PortWrite(PortConfig Port_Config , uint8_t value);

uint8_t MCAL_Dio_pinRead(PortConfig Port_Config , uint8_t Pin_number);
uint8_t MCAL_Dio_PortRead(PortConfig Port_Config);

void MCAL_Dio_PinToggle(PortConfig Port_Config , uint8_t Pin_number);

void MCAL_Dio_Pin_Input_PullUp(PortConfig Port_Config , uint8_t Pin_number);

#endif /* DIO_H_ */