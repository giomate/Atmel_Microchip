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
../ADF5610Driver.cpp \
../Device_Startup/startup_samd21.c \
../Device_Startup/system_samd21.c \
../main.cpp \
../SPI_Syn_Class.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADF5610Driver.o \
Device_Startup/startup_samd21.o \
Device_Startup/system_samd21.o \
main.o \
SPI_Syn_Class.o

OBJS_AS_ARGS +=  \
ADF5610Driver.o \
Device_Startup/startup_samd21.o \
Device_Startup/system_samd21.o \
main.o \
SPI_Syn_Class.o

C_DEPS +=  \
ADF5610Driver.d \
Device_Startup/startup_samd21.d \
Device_Startup/system_samd21.d \
main.d \
SPI_Syn_Class.d

C_DEPS_AS_ARGS +=  \
ADF5610Driver.d \
Device_Startup/startup_samd21.d \
Device_Startup/system_samd21.d \
main.d \
SPI_Syn_Class.d

OUTPUT_FILE_PATH +=ADF5610_SAMD_LIB.elf

OUTPUT_FILE_PATH_AS_ARGS +=ADF5610_SAMD_LIB.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Users/GMateusDP/Documents/Trobina/Development/Software/Atmel_Microchip/ADF5610_Handler/ADF5610_SAMD_BSP/Debug/libADF5610_SAMD_BSP.a

LINKER_SCRIPT_DEP+=  \
../Device_Startup/samd21j18a_flash.ld \
../Device_Startup/samd21j18a_sram.ld


# AVR32/GNU C Compiler
./ADF5610Driver.o: .././ADF5610Driver.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG -DEXACT_FREQ -DNOT_SDO  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../ADF5610_SAMD_BSP/Config" -I"../../ADF5610_SAMD_BSP" -I"../../ADF5610_SAMD_BSP/examples" -I"../../ADF5610_SAMD_BSP/hal/include" -I"../../ADF5610_SAMD_BSP/hal/utils/include" -I"../../ADF5610_SAMD_BSP/hpl/core" -I"../../ADF5610_SAMD_BSP/hpl/dmac" -I"../../ADF5610_SAMD_BSP/hpl/gclk" -I"../../ADF5610_SAMD_BSP/hpl/pm" -I"../../ADF5610_SAMD_BSP/hpl/port" -I"../../ADF5610_SAMD_BSP/hpl/sercom" -I"../../ADF5610_SAMD_BSP/hpl/sysctrl" -I"../../ADF5610_SAMD_BSP/hpl/systick" -I"../../ADF5610_SAMD_BSP/hpl/usb" -I"../../ADF5610_SAMD_BSP/hri" -I"../../ADF5610_SAMD_BSP/usb" -I"../../ADF5610_SAMD_BSP/usb/class/cdc" -I"../../ADF5610_SAMD_BSP/usb/class/cdc/device" -I"../../ADF5610_SAMD_BSP/usb/device"  -Og -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Device_Startup/startup_samd21.o: ../Device_Startup/startup_samd21.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Device_Startup/system_samd21.o: ../Device_Startup/system_samd21.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__SAMD21J18A__ -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include"  -Og -ffunction-sections -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG -DEXACT_FREQ -DNOT_SDO  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../ADF5610_SAMD_BSP/Config" -I"../../ADF5610_SAMD_BSP" -I"../../ADF5610_SAMD_BSP/examples" -I"../../ADF5610_SAMD_BSP/hal/include" -I"../../ADF5610_SAMD_BSP/hal/utils/include" -I"../../ADF5610_SAMD_BSP/hpl/core" -I"../../ADF5610_SAMD_BSP/hpl/dmac" -I"../../ADF5610_SAMD_BSP/hpl/gclk" -I"../../ADF5610_SAMD_BSP/hpl/pm" -I"../../ADF5610_SAMD_BSP/hpl/port" -I"../../ADF5610_SAMD_BSP/hpl/sercom" -I"../../ADF5610_SAMD_BSP/hpl/sysctrl" -I"../../ADF5610_SAMD_BSP/hpl/systick" -I"../../ADF5610_SAMD_BSP/hpl/usb" -I"../../ADF5610_SAMD_BSP/hri" -I"../../ADF5610_SAMD_BSP/usb" -I"../../ADF5610_SAMD_BSP/usb/class/cdc" -I"../../ADF5610_SAMD_BSP/usb/class/cdc/device" -I"../../ADF5610_SAMD_BSP/usb/device"  -Og -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./SPI_Syn_Class.o: .././SPI_Syn_Class.cpp
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -mthumb -D__SAMD21J18A__ -DDEBUG -DEXACT_FREQ -DNOT_SDO  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\arm\CMSIS\5.4.0\CMSIS\Core\Include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\SAMD21_DFP\1.3.395\samd21a\include" -I"../../ADF5610_SAMD_BSP/Config" -I"../../ADF5610_SAMD_BSP" -I"../../ADF5610_SAMD_BSP/examples" -I"../../ADF5610_SAMD_BSP/hal/include" -I"../../ADF5610_SAMD_BSP/hal/utils/include" -I"../../ADF5610_SAMD_BSP/hpl/core" -I"../../ADF5610_SAMD_BSP/hpl/dmac" -I"../../ADF5610_SAMD_BSP/hpl/gclk" -I"../../ADF5610_SAMD_BSP/hpl/pm" -I"../../ADF5610_SAMD_BSP/hpl/port" -I"../../ADF5610_SAMD_BSP/hpl/sercom" -I"../../ADF5610_SAMD_BSP/hpl/sysctrl" -I"../../ADF5610_SAMD_BSP/hpl/systick" -I"../../ADF5610_SAMD_BSP/hpl/usb" -I"../../ADF5610_SAMD_BSP/hri" -I"../../ADF5610_SAMD_BSP/usb" -I"../../ADF5610_SAMD_BSP/usb/class/cdc" -I"../../ADF5610_SAMD_BSP/usb/class/cdc/device" -I"../../ADF5610_SAMD_BSP/usb/device"  -Og -ffunction-sections -fno-rtti -fno-exceptions -mlong-calls -g3 -Wall -mcpu=cortex-m0plus -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mthumb -Wl,-Map="ADF5610_SAMD_LIB.map" --specs=nano.specs -Wl,--start-group -lm -lADF5610_SAMD_BSP  -Wl,--end-group -L"..\\Device_Startup" -L"C:\Users\GMATEU~1\DOCUME~1\Trobina\DEVELO~1\Software\ATMEL_~1\ADF561~1\ADF561~4\Debug"  -Wl,--gc-sections -mcpu=cortex-m0plus -Tsamd21j18a_flash.ld  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O binary "ADF5610_SAMD_LIB.elf" "ADF5610_SAMD_LIB.bin"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "ADF5610_SAMD_LIB.elf" "ADF5610_SAMD_LIB.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O binary "ADF5610_SAMD_LIB.elf" "ADF5610_SAMD_LIB.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objdump.exe" -h -S "ADF5610_SAMD_LIB.elf" > "ADF5610_SAMD_LIB.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "ADF5610_SAMD_LIB.elf" "ADF5610_SAMD_LIB.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-size.exe" "ADF5610_SAMD_LIB.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ADF5610_SAMD_LIB.elf" "ADF5610_SAMD_LIB.a" "ADF5610_SAMD_LIB.hex" "ADF5610_SAMD_LIB.bin" "ADF5610_SAMD_LIB.lss" "ADF5610_SAMD_LIB.eep" "ADF5610_SAMD_LIB.map" "ADF5610_SAMD_LIB.srec"
	