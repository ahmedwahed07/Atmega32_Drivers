################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../KEYPAD_cfg.c \
../KEYPAD_prog.c \
../LCD_Prog.c \
../main.c 

OBJS += \
./DIO_Prog.o \
./KEYPAD_cfg.o \
./KEYPAD_prog.o \
./LCD_Prog.o \
./main.o 

C_DEPS += \
./DIO_Prog.d \
./KEYPAD_cfg.d \
./KEYPAD_prog.d \
./LCD_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


