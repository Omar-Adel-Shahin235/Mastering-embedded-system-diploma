/*
 * LCD.c
 *
 * Created: 9/8/2023 12:41:17 AM
 *  Author: Acer
 */ 

#include "LCD.h"

void LCD_init()
{
	LCD_is_busy();
	
	//set control port as output
	LCD_Ctrl_Dir_PORT |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN);
	
//====================================================		
	#ifdef Eight_bit_mode
	//set data port as output
	LCD_Data_Dir_PORT |= 0xFF;
	
	LCD_clear_screen();
	_delay_ms(20);
	LCD_Write_command(Func_set_8bit_2line);
	#endif

	#ifdef Four_bit_mode
	//set data port as output
	LCD_Data_Dir_PORT |= 0xF0;
	LCD_clear_screen();
	_delay_ms(20);
	LCD_Write_command(0x02);
	LCD_Write_command(Func_set_4bit_2line);
	#endif
//====================================================		
	LCD_Write_command(Display_on_cursor_blink);
	LCD_Write_command(Entry_mode);
	LCD_Write_command(Begin_first_row);
}

void LCD_Write_command(unsigned char commmand)
{
	
	#ifdef Eight_bit_mode
	LCD_Ctrl_PORT &= ~((1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN)); //write command Instruction
	LCD_Data_PORT = commmand;
	LCD_kick();
	#endif
	
	#ifdef Four_bit_mode
	LCD_Data_PORT = (LCD_Data_PORT &(0x0F)) | (commmand & 0xF0);
	LCD_Ctrl_PORT &= ~((1<<LCD_RS) | (1<<LCD_RW));
	_delay_ms(1);
	LCD_kick();
	LCD_Data_PORT = (LCD_Data_PORT &(0x0F)) | ((commmand & 0x0F)<<4);
	LCD_Ctrl_PORT &= ~((1<<LCD_RS) | (1<<LCD_RW));
	_delay_ms(1);
	LCD_kick();
	_delay_ms(5);
	#endif
}

void LCD_Write_char(unsigned char data)
{
	
	#ifdef Eight_bit_mode
	//write data
	LCD_Ctrl_PORT &= ~((1<<LCD_RW) | (1<<LCD_EN));
	LCD_Ctrl_PORT |= (1<<LCD_RS);
	
	LCD_Data_PORT = data;
	LCD_kick();
	#endif
	
	#ifdef Four_bit_mode
	
	LCD_Data_PORT = (LCD_Data_PORT &(0x0F)) | (data & 0xF0);
	
	LCD_Ctrl_PORT &= ~(1<<LCD_RW);
	LCD_Ctrl_PORT |= (1<<LCD_RS);
	_delay_ms(1);
	LCD_kick();
	
	LCD_Data_PORT = (LCD_Data_PORT &(0x0F)) | ((data & 0x0F)<<4);
	LCD_Ctrl_PORT &= ~(1<<LCD_RW);
	LCD_Ctrl_PORT |= (1<<LCD_RS);
	_delay_ms(1);
	LCD_kick();
	
	_delay_ms(5);
	#endif
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
	#ifdef Eight_bit_mode
	LCD_Ctrl_Dir_PORT |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN);
	LCD_Data_Dir_PORT = 0x00;
	
	LCD_Ctrl_PORT &= ~(1<<LCD_RS); //command register select
	
	LCD_Ctrl_PORT |= (1<<LCD_RW); //read mode
	
	LCD_kick();
	
	LCD_Data_Dir_PORT = 0xFF;
	LCD_Ctrl_PORT &= ~(1<<LCD_RW); //write
	#endif
	
	#ifdef Four_bit_mode
	LCD_Ctrl_Dir_PORT |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN);
	LCD_Data_Dir_PORT &= ~(0xFF<<4);
	
		LCD_Ctrl_PORT &= ~(1<<LCD_RS); //command register select
		
		LCD_Ctrl_PORT |= (1<<LCD_RW); //read mode
		
		LCD_kick();
		
		LCD_Data_Dir_PORT |= 0xF0;
		LCD_Ctrl_PORT &= ~(1<<LCD_RW); //write
	#endif
}

void LCD_kick()
{
	LCD_Ctrl_PORT |= (1<<LCD_EN); //set enable
	_delay_ms(5);
	LCD_Ctrl_PORT &= ~(1<<LCD_EN); //Reset enable
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