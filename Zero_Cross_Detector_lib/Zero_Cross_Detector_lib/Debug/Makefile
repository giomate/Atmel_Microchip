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

OUTPUT_FILE_PATH +=libZero_Cross_Detector_lib.a

OUTPUT_FILE_PATH_AS_ARGS +=libZero_Cross_Detector_lib.a

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Users/GMateusDP/Documents/Trobina/Development/Software/Atmel_Microchip/AVR_CURIOSITY_BSP/AVR_CURIOSITY_BSP/Debug/libAVR_CURIOSITY_BSP.a

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


$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Archiver : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-ar.exe$(QUOTE) -r  -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) 
	@echo Finished building target: $@
	
	




# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "libZero_Cross_Detector_lib.elf" "libZero_Cross_Detector_lib.a" "libZero_Cross_Detector_lib.hex" "libZero_Cross_Detector_lib.lss" "libZero_Cross_Detector_lib.eep" "libZero_Cross_Detector_lib.map" "libZero_Cross_Detector_lib.srec" "libZero_Cross_Detector_lib.usersignatures"
	