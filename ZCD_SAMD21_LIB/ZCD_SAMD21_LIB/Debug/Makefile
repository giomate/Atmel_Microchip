################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Device_Startup/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Device_Startup/startup_samd21.c \
../Device_Startup/system_samd21.c \
../main.cpp \
../SPI_Syn_ZCD_Class.cpp \
../ZCD_Handler.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Device_Startup/startup_samd21.o \
Device_Startup/system_samd21.o \
main.o \
SPI_Syn_ZCD_Class.o \
ZCD_Handler.o

OBJS_AS_ARGS +=  \
Device_Startup/startup_samd21.o \
Device_Startup/system_samd21.o \
main.o \
SPI_Syn_ZCD_Class.o \
ZCD_Handler.o

C_DEPS +=  \
Device_Startup/startup_samd21.d \
Device_Startup/system_samd21.d \
main.d \
SPI_Syn_ZCD_Class.d \
ZCD_Handler.d

C_DEPS_AS_ARGS +=  \
Device_Startup/startup_samd21.d \
Device_Startup/system_samd21.d \
main.d \
SPI_Syn_ZCD_Class.d \
ZCD_Handler.d

OUTPUT_FILE_PATH +=libZCD_SAMD21_LIB.a

OUTPUT_FILE_PATH_AS_ARGS +=libZCD_SAMD21_LIB.a

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Salukat/Purificador/SoftwareDevelopment/Atmel_Microchip/USB_SAMD21_HANDLER/USB_SAMD21_HANDLER/Debug/libUSB_SAMD21_HANDLER.a

LINKER_SCRIPT_DEP+=  \
../Device_Startup/samd21j18a_flash.ld \
../Device_Startup/samd21j18a_sram.ld


# AVR32/GNU C Compiler
Device_Startup/startup_samd21.o: ../Device_Startup/startup_samd21.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Device_Startup/system_samd21.o: ../Device_Startup/system_samd21.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../../SAMD21_BSP/SAMD21_BSP/Config" -I"../../../SAMD21_BSP/SAMD21_BSP" -I"../../../SAMD21_BSP/SAMD21_BSP/examples" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/utils/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/core" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dmac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/gclk" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/pm" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/port" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sercom" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sysctrl" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/systick" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/hri" -I"../../../SAMD21_BSP/SAMD21_BSP/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc/device" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/device" -I"../../../SAMD21_BSP/SAMD21_BSP/stdio_redirect" -I"../../../USB_SAMD21_HANDLER/USB_SAMD21_HANDLER" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/tc"  -O0 -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./SPI_Syn_ZCD_Class.o: .././SPI_Syn_ZCD_Class.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../../SAMD21_BSP/SAMD21_BSP/Config" -I"../../../SAMD21_BSP/SAMD21_BSP" -I"../../../SAMD21_BSP/SAMD21_BSP/examples" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/utils/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/core" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dmac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/gclk" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/pm" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/port" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sercom" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sysctrl" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/systick" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/hri" -I"../../../SAMD21_BSP/SAMD21_BSP/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc/device" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/device" -I"../../../SAMD21_BSP/SAMD21_BSP/stdio_redirect" -I"../../../USB_SAMD21_HANDLER/USB_SAMD21_HANDLER" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/tc"  -O0 -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./ZCD_Handler.o: .././ZCD_Handler.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../../SAMD21_BSP/SAMD21_BSP/Config" -I"../../../SAMD21_BSP/SAMD21_BSP" -I"../../../SAMD21_BSP/SAMD21_BSP/examples" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/utils/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/core" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dmac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/gclk" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/pm" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/port" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sercom" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sysctrl" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/systick" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/hri" -I"../../../SAMD21_BSP/SAMD21_BSP/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc/device" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/device" -I"../../../SAMD21_BSP/SAMD21_BSP/stdio_redirect" -I"../../../USB_SAMD21_HANDLER/USB_SAMD21_HANDLER" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/tc"  -O0 -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)


$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Archiver : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-ar.exe$(QUOTE) -r  -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) 
	@echo Finished building target: $@
	
	




# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "libZCD_SAMD21_LIB.elf" "libZCD_SAMD21_LIB.a" "libZCD_SAMD21_LIB.hex" "libZCD_SAMD21_LIB.bin" "libZCD_SAMD21_LIB.lss" "libZCD_SAMD21_LIB.eep" "libZCD_SAMD21_LIB.map" "libZCD_SAMD21_LIB.srec"
	