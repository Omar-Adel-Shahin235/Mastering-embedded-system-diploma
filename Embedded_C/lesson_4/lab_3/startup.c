#include <stdint.h>

void Reset_handler();
extern int main(void);
void default_handler(){
	
Reset_handler();
}

void _1_handler() __attribute__((weak,alias("default_handler")));;
void _2_handler() __attribute__((weak,alias("default_handler")));;

 
//book 1024 bytes located by .bss through unintialized array of 256 integer element

static unsigned long Stack_top[256];

/*
uint32_t vectors[] __attribute__((section(".vectors"))) =
{
(uint32_t) (Stack_top+sizeof(Stack_top)), 
(uint32_t) &Reset_handler,
(uint32_t) &_1_handler,
(uint32_t) &_2_handler,
};
*/

void (* const g_p_fun_vectors[])() __attribute__((section(".vectors"))) =
{
	(void(*)())((unsigned long)Stack_top+sizeof(Stack_top)) , 
	&Reset_handler,
	&_1_handler,
	&_2_handler,
};	


extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;


void Reset_handler(){
	
	//copy data section from flash to sram
	
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data; 
	unsigned char* p_src =  (unsigned char*)&_E_text;
	unsigned char* p_dst =  (unsigned char*)&_S_data;
	int i=0;
	for( i; i<data_size ; i++)
	{
	*((unsigned char*)p_dst++) = *((unsigned char*)p_src++);
	}
	
	//init bss section in sram
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss; 
	p_dst =  (unsigned char*)&_S_bss;
	 int j=0;
	for( j ; j<bss_size ; j++)
	{
	*((unsigned char*)p_dst++) = (unsigned char)0;
	}
	
	//jump main() function

	main();
}

// C:\Users\user\AppData\Local\Temp\VSM Studio\93596eae5a1b43228b531763b1d2812c\STM32F103R6_1