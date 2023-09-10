/*
 * Key_pad.c
 *
 * Created: 9/8/2023 1:46:26 AM
 *  Author: Acer
 */ 

#include "Key_pad.h"

GPIO_PinConfig_t PinCfg;

int Key_pad_rows[4]= {R0 , R1 , R2 , R3};
int Key_pad_column[4]= {C0 , C1 , C2 , C3};

void Key_pad_init()
{
	//R0 TO R4 as OUTPUT
	PinCfg.GPIO_pinNumber = R0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = R1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = R2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = R3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );



	//C0 TO C4 as output
	PinCfg.GPIO_pinNumber = C0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = C1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = C2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );

	PinCfg.GPIO_pinNumber = C3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(Key_pad_PORT , &PinCfg );



	//set R0 to R4 and C0 to C4 to have output 1
	MCAL_GPIO_WritePin(Key_pad_PORT, R0 , GPIO_PIN_true);
	MCAL_GPIO_WritePin(Key_pad_PORT, R1 , GPIO_PIN_true);
	MCAL_GPIO_WritePin(Key_pad_PORT, R2 , GPIO_PIN_true);
	MCAL_GPIO_WritePin(Key_pad_PORT, R3 , GPIO_PIN_true);

	MCAL_GPIO_WritePin(Key_pad_PORT, C0 , GPIO_PIN_true);
	MCAL_GPIO_WritePin(Key_pad_PORT, C1 , GPIO_PIN_true);
	MCAL_GPIO_WritePin(Key_pad_PORT, C2 , GPIO_PIN_true);
	MCAL_GPIO_WritePin(Key_pad_PORT, C3 , GPIO_PIN_true);

}

char Key_pad_get_char()
{
	int i,j;

	for(i=0 ; i<4 ; i++)
	{
		//set C0 to C4 to have output 1
			MCAL_GPIO_WritePin(Key_pad_PORT, C0 , GPIO_PIN_true);
			MCAL_GPIO_WritePin(Key_pad_PORT, C1 , GPIO_PIN_true);
			MCAL_GPIO_WritePin(Key_pad_PORT, C2 , GPIO_PIN_true);
			MCAL_GPIO_WritePin(Key_pad_PORT, C3 , GPIO_PIN_true);

		//Column to have output 0
			MCAL_GPIO_WritePin(Key_pad_PORT, Key_pad_column[i] , GPIO_PIN_false);
		//_delay_ms(30);

		for(j=0 ; j<4 ; j++)
		{
			if( (MCAL_GPIO_ReadPin(Key_pad_PORT,Key_pad_rows[j]))==0 )
			{
				while( (MCAL_GPIO_ReadPin(Key_pad_PORT,Key_pad_rows[j]))==0 );
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
