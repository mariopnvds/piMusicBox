################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fsm.c \
../kbhit.c \
../lcd.c \
../mfrc522.c \
../mfrc522_hal_linux.c \
../piMusicBox_1.c \
../rfid.c \
../tmr.c 

OBJS += \
./fsm.o \
./kbhit.o \
./lcd.o \
./mfrc522.o \
./mfrc522_hal_linux.o \
./piMusicBox_1.o \
./rfid.o \
./tmr.o 

C_DEPS += \
./fsm.d \
./kbhit.d \
./lcd.d \
./mfrc522.d \
./mfrc522_hal_linux.d \
./piMusicBox_1.d \
./rfid.d \
./tmr.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -IC:\SysGCC\raspberry\include -IC:\SysGCC\raspberry\include\wiringPi -O0 -g3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


