/*
 * Key_pad.c
 *
 * Created: 9/8/2023 1:46:26 AM
 *  Author: Acer
 */ 

#include "Key_pad.h"

int Key_pad_rows[4]= {R0 , R1 , R2 , R3};
int Key_pad_column[4]= {C0 , C1 , C2 , C3};

void Key_pad_init()
{
	//R0 TO R4 as input
	Key_pad_Dir_PORT &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
	
	//C0 TO C4 as output
	Key_pad_Dir_PORT |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
	
	//set R0 to R4 as pull up and C0 to C4 to have output 1
	Key_pad_PORT = 0xFF;
}

char Key_pad_get_char()
{
	int i,j;
	
	for(i=0 ; i<4 ; i++)
	{
		Key_pad_PORT |= (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);
		
		//Column to have output 0
		Key_pad_PORT &= ~(1<<Key_pad_column[i]);
		//_delay_ms(30);
		for(j=0 ; j<4 ; j++)
		{
			if( !(Key_pad_PIN & (1<<Key_pad_rows[j])))
			{
				while( !(Key_pad_PIN & (1<<Key_pad_rows[j])));
				switch(i)
				{
				//====================================
					case 0:
					if(j==0)
						return '7';
						
					else if(j==1)
						return '4';
						
					else if(j==2)
						return '1';
					
					else if(j==3)
						return '!';
					break;
				//======================================			
					case 1:
					if(j==0)
						return '8';
					
					else if(j==1)
						return '5';
					
					else if(j==2)
						return '2';
					
					else if(j==3)
						return '0';
					break;
				//========================================	
					case 2:
					if(j==0)
						return '9';
					
					else if(j==1)
						return '6';
					
					else if(j==2)
						return '3';
					
					else if(j==3)
						return '=';
					break;
				//=======================================		
					case 3:
					if(j==0)
						return '/';
					
					else if(j==1)
						return '*';
					
					else if(j==2)
						return '-';
					
					else if(j==3)
						return '+';
					break;
				}
			}
		}
	}
 return 'N';
}