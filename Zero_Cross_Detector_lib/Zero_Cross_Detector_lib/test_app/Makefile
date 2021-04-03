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
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.cpp \
../Zero_Cross_Counter.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
Zero_Cross_Counter.o

OBJS_AS_ARGS +=  \
main.o \
Zero_Cross_Counter.o

C_DEPS +=  \
main.d \
Zero_Cross_Counter.d

C_DEPS_AS_ARGS +=  \
main.d \
Zero_Cross_Counter.d

OUTPUT_FILE_PATH +=Zero_Cross_Detector_lib.elf

OUTPUT_FILE_PATH_AS_ARGS +=Zero_Cross_Detector_lib.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Users/GMateusDP/Documents/Trobina/Development/Software/Atmel_Microchip/AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/test_app/libAVR_CURIOSITY_BSP.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./main.o: .././main.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\AVR-Dx_DFP\1.7.85\include" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/examples/include" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/include" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/utils" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/utils/assembler" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/src" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/Config"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=avr128db48 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\AVR-Dx_DFP\1.7.85\gcc\dev\avr128db48" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./Zero_Cross_Counter.o: .././Zero_Cross_Counter.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\AVR-Dx_DFP\1.7.85\include" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/examples/include" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/include" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/utils" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/utils/assembler" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/src" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP" -I"../../../AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/Config"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=avr128db48 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\AVR-Dx_DFP\1.7.85\gcc\dev\avr128db48" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Zero_Cross_Detector_lib.map" -Wl,--start-group -Wl,-lm -Wl,-lAVR_CURIOSITY_BSP  -Wl,--end-group -Wl,-L"C:\Users\GMATEU~1\DOCUME~1\Trobina\DEVELO~1\Software\ATMEL_~1\AVR_CU~1\AVR_CU~1\test_app"  -Wl,--gc-sections -mmcu=avr128db48 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\AVR-Dx_DFP\1.7.85\gcc\dev\avr128db48"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Zero_Cross_Detector_lib.elf" "Zero_Cross_Detector_lib.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Zero_Cross_Detector_lib.elf" "Zero_Cross_Detector_lib.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Zero_Cross_Detector_lib.elf" > "Zero_Cross_Detector_lib.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Zero_Cross_Detector_lib.elf" "Zero_Cross_Detector_lib.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Zero_Cross_Detector_lib.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Zero_Cross_Detector_lib.elf" "Zero_Cross_Detector_lib.a" "Zero_Cross_Detector_lib.hex" "Zero_Cross_Detector_lib.lss" "Zero_Cross_Detector_lib.eep" "Zero_Cross_Detector_lib.map" "Zero_Cross_Detector_lib.srec" "Zero_Cross_Detector_lib.usersignatures"
	