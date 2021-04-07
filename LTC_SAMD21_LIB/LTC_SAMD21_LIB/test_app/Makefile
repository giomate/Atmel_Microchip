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
../LTC5548HANDLER.cpp \
../main.cpp \
../MIXER_TUNNER_HELPER.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Device_Startup/startup_samd21.o \
Device_Startup/system_samd21.o \
LTC5548HANDLER.o \
main.o \
MIXER_TUNNER_HELPER.o

OBJS_AS_ARGS +=  \
Device_Startup/startup_samd21.o \
Device_Startup/system_samd21.o \
LTC5548HANDLER.o \
main.o \
MIXER_TUNNER_HELPER.o

C_DEPS +=  \
Device_Startup/startup_samd21.d \
Device_Startup/system_samd21.d \
LTC5548HANDLER.d \
main.d \
MIXER_TUNNER_HELPER.d

C_DEPS_AS_ARGS +=  \
Device_Startup/startup_samd21.d \
Device_Startup/system_samd21.d \
LTC5548HANDLER.d \
main.d \
MIXER_TUNNER_HELPER.d

OUTPUT_FILE_PATH +=LTC_SAMD21_LIB.elf

OUTPUT_FILE_PATH_AS_ARGS +=LTC_SAMD21_LIB.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Salukat/Purificador/SoftwareDevelopment/Atmel_Microchip/ADF_SAMD21_LIB/ADF_SAMD21_LIB/library/libADF_SAMD21_LIB.a \
C:/Salukat/Purificador/SoftwareDevelopment/Atmel_Microchip/LMX_SAMD21_LIB/LMX_SAMD21_LIB/library/libLMX_SAMD21_LIB.a \
C:/Salukat/Purificador/SoftwareDevelopment/Atmel_Microchip/SAMD21_BSP/SAMD21_BSP/Debug/libSAMD21_BSP.a \
C:/Salukat/Purificador/SoftwareDevelopment/Atmel_Microchip/USB_SAMD21_HANDLER/USB_SAMD21_HANDLER/library/libUSB_SAMD21_HANDLER.a \
C:/Salukat/Purificador/SoftwareDevelopment/Atmel_Microchip/ZCD_SAMD21_LIB/ZCD_SAMD21_LIB/library/libZCD_SAMD21_LIB.a

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
	

./LTC5548HANDLER.o: .././LTC5548HANDLER.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../../SAMD21_BSP/SAMD21_BSP/Config" -I"../../../SAMD21_BSP/SAMD21_BSP" -I"../../../SAMD21_BSP/SAMD21_BSP/examples" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/utils/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/core" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dmac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/gclk" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/pm" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/port" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sercom" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sysctrl" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/systick" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/hri" -I"../../../SAMD21_BSP/SAMD21_BSP/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc/device" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/device" -I"../../../SAMD21_BSP/SAMD21_BSP/stdio_redirect" -I"../../../USB_SAMD21_HANDLER/USB_SAMD21_HANDLER" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/tc" -I"../../../ADF_SAMD21_LIB/ADF_SAMD21_LIB" -I"../../../LMX_SAMD21_LIB/LMX_SAMD21_LIB" -I"../../../ZCD_SAMD21_LIB/ZCD_SAMD21_LIB"  -Og -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../../SAMD21_BSP/SAMD21_BSP/Config" -I"../../../SAMD21_BSP/SAMD21_BSP" -I"../../../SAMD21_BSP/SAMD21_BSP/examples" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/utils/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/core" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dmac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/gclk" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/pm" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/port" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sercom" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sysctrl" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/systick" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/hri" -I"../../../SAMD21_BSP/SAMD21_BSP/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc/device" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/device" -I"../../../SAMD21_BSP/SAMD21_BSP/stdio_redirect" -I"../../../USB_SAMD21_HANDLER/USB_SAMD21_HANDLER" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/tc" -I"../../../ADF_SAMD21_LIB/ADF_SAMD21_LIB" -I"../../../LMX_SAMD21_LIB/LMX_SAMD21_LIB" -I"../../../ZCD_SAMD21_LIB/ZCD_SAMD21_LIB"  -Og -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./MIXER_TUNNER_HELPER.o: .././MIXER_TUNNER_HELPER.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\cmsis\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../../SAMD21_BSP/SAMD21_BSP/Config" -I"../../../SAMD21_BSP/SAMD21_BSP" -I"../../../SAMD21_BSP/SAMD21_BSP/examples" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hal/utils/include" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/core" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/dmac" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/gclk" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/pm" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/port" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sercom" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/sysctrl" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/systick" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/hri" -I"../../../SAMD21_BSP/SAMD21_BSP/usb" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/class/cdc/device" -I"../../../SAMD21_BSP/SAMD21_BSP/usb/device" -I"../../../SAMD21_BSP/SAMD21_BSP/stdio_redirect" -I"../../../USB_SAMD21_HANDLER/USB_SAMD21_HANDLER" -I"../../../SAMD21_BSP/SAMD21_BSP/hpl/tc" -I"../../../ADF_SAMD21_LIB/ADF_SAMD21_LIB" -I"../../../LMX_SAMD21_LIB/LMX_SAMD21_LIB" -I"../../../ZCD_SAMD21_LIB/ZCD_SAMD21_LIB"  -Og -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mthumb -Wl,-Map="LTC_SAMD21_LIB.map" --specs=nosys.specs -Wl,--start-group -lm -lADF_SAMD21_LIB -lLMX_SAMD21_LIB -lSAMD21_BSP -lUSB_SAMD21_HANDLER -lZCD_SAMD21_LIB  -Wl,--end-group -L"..\\Device_Startup" -L"C:\Salukat\Purificador\SoftwareDevelopment\Atmel_Microchip\ADF_SAMD21_LIB\ADF_SAMD21_LIB\library" -L"C:\Salukat\Purificador\SoftwareDevelopment\Atmel_Microchip\LMX_SAMD21_LIB\LMX_SAMD21_LIB\library" -L"C:\Salukat\Purificador\SoftwareDevelopment\Atmel_Microchip\SAMD21_BSP\SAMD21_BSP\Debug" -L"C:\Salukat\PURIFI~1\SOFTWA~1\ATMEL_~1\USB_SA~1\USB_SA~1\library" -L"C:\Salukat\Purificador\SoftwareDevelopment\Atmel_Microchip\ZCD_SAMD21_LIB\ZCD_SAMD21_LIB\library"  -Wl,--gc-sections -mcpu=cortex-m0plus -Tsamd21j18a_flash.ld  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O binary "LTC_SAMD21_LIB.elf" "LTC_SAMD21_LIB.bin"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "LTC_SAMD21_LIB.elf" "LTC_SAMD21_LIB.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O binary "LTC_SAMD21_LIB.elf" "LTC_SAMD21_LIB.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objdump.exe" -h -S "LTC_SAMD21_LIB.elf" > "LTC_SAMD21_LIB.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "LTC_SAMD21_LIB.elf" "LTC_SAMD21_LIB.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-size.exe" "LTC_SAMD21_LIB.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "LTC_SAMD21_LIB.elf" "LTC_SAMD21_LIB.a" "LTC_SAMD21_LIB.hex" "LTC_SAMD21_LIB.bin" "LTC_SAMD21_LIB.lss" "LTC_SAMD21_LIB.eep" "LTC_SAMD21_LIB.map" "LTC_SAMD21_LIB.srec"
	