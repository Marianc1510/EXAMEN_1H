################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Parcial_1.c \
../src/calculos.c \
../src/cliente.c \
../src/informes.c \
../src/publicidad.c \
../src/utN.c 

OBJS += \
./src/Parcial_1.o \
./src/calculos.o \
./src/cliente.o \
./src/informes.o \
./src/publicidad.o \
./src/utN.o 

C_DEPS += \
./src/Parcial_1.d \
./src/calculos.d \
./src/cliente.d \
./src/informes.d \
./src/publicidad.d \
./src/utN.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


