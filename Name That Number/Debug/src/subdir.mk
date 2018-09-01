################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Name\ That\ Number.cpp 

OBJS += \
./src/Name\ That\ Number.o 

CPP_DEPS += \
./src/Name\ That\ Number.d 


# Each subdirectory must supply rules for building sources it contributes
src/Name\ That\ Number.o: ../src/Name\ That\ Number.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Name That Number.d" -MT"src/Name\ That\ Number.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


