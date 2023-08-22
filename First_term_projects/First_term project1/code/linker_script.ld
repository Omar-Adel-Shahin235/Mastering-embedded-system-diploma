/* Startup for cortex-m3 
Eng.omar adel
*/

MEMORY
{
flash : ORIGIN = 0x00000000 , LENGTH = 512M
sram : ORIGIN = 0x20000000 , LENGTH = 512M
}

SECTIONS
{
	.text : {
			*(.vectors*)
			*(.text*)
			*(.rodata)
			_E_text = . ;
	
	}> flash
	
	.data : {
	_S_data = . ;
			*(.data)
	_E_data = . ;
	. = ALIGN(4) ;
	}> sram AT> flash
	
	.bss : {
	_S_bss = . ;
			*(.bss*)
	_E_bss = . ;
	
	
	}> sram
	
}