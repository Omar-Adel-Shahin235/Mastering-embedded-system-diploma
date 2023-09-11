/*
 * LCD.c
 *
 * Created: 9/8/2023 12:41:17 AM
 *  Author: Acer
 */ 

#include "LCD.h"
#include <stdio.h>

void _delay_ms(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<255;j++);
	}
}

GPIO_PinConfig_t PinCfg;

void LCD_init()
{
	LCD_is_busy();

	LCD_clear_screen();
	_delay_ms(20);
	LCD_Write_command(Func_set_8bit_2line);

	LCD_Write_command(Display_on_cursor_blink);
	LCD_Write_command(Entry_mode);
	LCD_Write_command(Begin_first_row);
}

void LCD_Write_command(unsigned char commmand)
{
	MCAL_GPIO_WritePort(LCD_Data_PORT,commmand);
	
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_RS , GPIO_PIN_false);
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_RW , GPIO_PIN_false);
	_delay_ms(1);
	LCD_kick();

}

void LCD_Write_char(unsigned char data)
{
	MCAL_GPIO_WritePort(LCD_Data_PORT,data);

	//write data
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_RW , GPIO_PIN_false);
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_RS , GPIO_PIN_true);
	_delay_ms(1);
	LCD_kick();
}
void LCD_Write_string(char* string)
{
	int count =0;
	for(count = 0 ; (string[count]!='\0') ; count++)
	{
		if(count == 16)
			LCD_Location(2,0);

		if(count == 32)
		{
			LCD_clear_screen();
			LCD_Location(1,0);
		}

		LCD_Write_char(string[count]);
	}
}

void LCD_is_busy(void)
{


	//LCD_RS output push-pull
	PinCfg.GPIO_pinNumber = LCD_RS;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Ctrl_PORT , &PinCfg );

	//LCD_RW output push-pull
	PinCfg.GPIO_pinNumber = LCD_RW;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Ctrl_PORT , &PinCfg );

	//LCD_RW output push-pull
	PinCfg.GPIO_pinNumber = LCD_EN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Ctrl_PORT , &PinCfg );

	//Data port as input
	PinCfg.GPIO_pinNumber = GPIO_PIN0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );


	//command register select
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_RS , GPIO_PIN_false);

	//read mode
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_RW , GPIO_PIN_true);

	LCD_kick();

	//Data port as output
	PinCfg.GPIO_pinNumber = GPIO_PIN0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = GPIO_PIN7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_Data_PORT , &PinCfg );


	//Write mode
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_RW , GPIO_PIN_true);
}

void LCD_kick()
{
	//set enable
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_EN , GPIO_PIN_true);
	_delay_ms(5);
	MCAL_GPIO_WritePin(LCD_Ctrl_PORT, LCD_EN , GPIO_PIN_false); //Reset enable
}

void LCD_clear_screen(void)
{
	LCD_Write_command(Clear_display);
}

void LCD_Location(unsigned char row , unsigned char column)
{
	switch(row)
	{
	case 1:
		LCD_Write_command(Begin_first_row + column);
		break;

	case 2:
		LCD_Write_command(Begin_second_row + column);
		break;
	}
}


void LCD_Custom_charachters()
{
	//To enable CGRAM and to save custom char
	LCD_Write_command(64);

	//Angry face
	LCD_Write_char(0b00000);
	LCD_Write_char(0b10001);
	LCD_Write_char(0b11011);
	LCD_Write_char(0b00000);
	LCD_Write_char(0b00000);
	LCD_Write_char(0b01110);
	LCD_Write_char(0b10001);
	LCD_Write_char(0b00000);

	LCD_Write_command(Begin_first_row);
	LCD_Write_char(0); //display the first custom char
	_delay_ms(10);
}

void LCD_Write_Number(signed int Number)
{

	char str[5];

	sprintf(str ,"%d",Number);

	LCD_Write_string(str);

}

void LCD_Write_real_Number(double Number)
{
	char str[10];

	int True_num = Number;
	float point = Number - True_num;

	int after_sign = point*1000;

	sprintf(str ,"%d.%.2d" ,True_num , after_sign );
	LCD_Write_string(str);
}


