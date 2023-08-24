CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC =$(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS =$(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_name = Final_project_1

all: $(Project_name).bin
	@echo "Build is done"


%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) -mthumb $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $(Project_name).elf $(Project_name).bin
	cp $(Project_name).elf $(Project_name).axf

clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin