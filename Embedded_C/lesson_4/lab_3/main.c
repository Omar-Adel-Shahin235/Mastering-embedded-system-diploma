

#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0x400fe108))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551c))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253fc))

int main(){
	
	volatile unsigned long delay_counter;
	SYSCTL_RCGC2_R = 0x20;
	
	//delay to make sure GPIO is up and running
	for(delay_counter = 0 ; delay_counter <200 ; delay_counter++ );
	
	//Output direction for bit3 on PORTF
	GPIO_PORTF_DIR_R |= (1<<3);
	
	//Enable bit3 on PORTF
	GPIO_PORTF_DEN_R |= (1<<3);
	
	while(1)
	{
		//bit3 at PORTF is on
		GPIO_PORTF_DATA_R |= (1<<3);
		
		//bit3 delay on
		for(delay_counter = 0 ; delay_counter <200000 ; delay_counter++ );
		
		//bit3 at PORTF is off
		GPIO_PORTF_DATA_R &= ~(1<<3);
		
		//bit3 delay off
		for(delay_counter = 0 ; delay_counter <200000 ; delay_counter++ );
	}
	
	return 0;
}