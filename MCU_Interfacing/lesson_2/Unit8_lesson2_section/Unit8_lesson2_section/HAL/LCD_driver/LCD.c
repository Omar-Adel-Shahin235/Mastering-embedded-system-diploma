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
//	LCD_Ctrl_Dir_PORT |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN);
	
//====================================================		
	#ifdef Eight_bit_mode
	//set data port as output
//	LCD_Data_Dir_PORT |= 0xFF;
	
	LCD_clear_screen();
	_delay_ms(20);
	LCD_Write_command(Func_set_8bit_2line);
	#endif

	#ifdef Four_bit_mode
	//set data port as output
//	LCD_Data_Dir_PORT |= 0xF0;
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
	//LCD_Ctrl_PORT &= ~((1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN)); //write command Instruction
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RS , 0);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RW , 0);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_EN , 0);
	
	MCAL_Dio_PortWrite(LCD_Data_PORT , commmand);
	
	LCD_kick();
	#endif
	
	#ifdef Four_bit_mode
	LCD_in_port = (LCD_in_port &(0x0F)) | (commmand & 0xF0);
	
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RS , 0);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RW , 0);
	
	_delay_ms(100);
	LCD_kick();
	
	LCD_in_port = (LCD_in_port &(0x0F)) | ((commmand & 0x0F)<<4);
	
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RS , 0);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RW , 0);
	
	_delay_ms(100);
	LCD_kick();
	
	_delay_ms(5);
	#endif
}

void LCD_Write_char(unsigned char data)
{
	
	#ifdef Eight_bit_mode
	//write data
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RS , 1);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RW , 0);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_EN , 0);
	
	MCAL_Dio_PortWrite(LCD_Data_PORT , data);
	LCD_kick();
	#endif
	
	#ifdef Four_bit_mode
	
	LCD_in_port = (LCD_in_port &(0x0F)) | (data & 0xF0);
	
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RS , 1);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RW , 0);
	
	_delay_ms(100);
	LCD_kick();
	
	LCD_in_port = (LCD_in_port &(0x0F)) | ((data & 0x0F)<<4);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RS , 1);
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT , LCD_RW , 0);
	
	_delay_ms(100);
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

	MCAL_Dio_pinDirection(LCD_Ctrl_PORT ,LCD_RS ,Output_Statues);
	MCAL_Dio_pinDirection(LCD_Ctrl_PORT ,LCD_RW ,Output_Statues);
	MCAL_Dio_pinDirection(LCD_Ctrl_PORT ,LCD_EN ,Output_Statues);
	
	MCAL_Dio_PortDirection(LCD_Data_PORT ,Input_Statues);
	
	 //command register select
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_RS , 0 );
	
	//read mode
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_RW , 1 );
	
	LCD_kick();
	
	//LCD_Data_Dir_PORT = 0xFF;
	MCAL_Dio_PortDirection(LCD_Data_PORT ,Output_Statues);
	
	//write mode
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_RW , 0 );
	
	#endif
	
	#ifdef Four_bit_mode
	
	MCAL_Dio_pinDirection(LCD_Ctrl_PORT ,LCD_RS ,Output_Statues);
	MCAL_Dio_pinDirection(LCD_Ctrl_PORT ,LCD_RW ,Output_Statues);
	MCAL_Dio_pinDirection(LCD_Ctrl_PORT ,LCD_EN ,Output_Statues);
	
	
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D4 ,Input_Statues);
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D5 ,Input_Statues);
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D6 ,Input_Statues);
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D7 ,Input_Statues);
	
	_delay_ms(5);
	
	//command register select
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_RS , 0 );
		
	//read mode
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_RW , 1 );
		
	LCD_kick();
		
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D4 ,Output_Statues);
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D5 ,Output_Statues);
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D6 ,Output_Statues);
	MCAL_Dio_pinDirection(LCD_Data_PORT ,LCD_D7 ,Output_Statues);
	
	//write mode
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_RW , 0 );
	#endif
}

void LCD_kick()
{
	//set enable
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_EN , 1 );
	_delay_ms(5);
	//Reset enable
	MCAL_Dio_pinWrite(LCD_Ctrl_PORT ,LCD_EN , 0 );
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