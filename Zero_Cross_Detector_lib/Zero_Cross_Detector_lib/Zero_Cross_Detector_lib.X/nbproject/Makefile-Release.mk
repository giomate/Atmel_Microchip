#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Release.mk)" "nbproject/Makefile-local-Release.mk"
include nbproject/Makefile-local-Release.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Release
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../main.cpp ../SPI_SLAVE_CLASS.cpp ../Zero_Cross_Counter.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o

# Source Files
SOURCEFILES=../main.cpp ../SPI_SLAVE_CLASS.cpp ../Zero_Cross_Counter.cpp

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/avr128db48"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Release.mk dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=AVR128DB48
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  .generated_files/cae94d8e7bb25f192bf5c6f5d95e7e1f737f0573.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48" -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DNDEBUG -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/main.o.d" -MT "${OBJECTDIR}/_ext/1472/main.o.d" -MT ${OBJECTDIR}/_ext/1472/main.o  -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp  -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o: ../SPI_SLAVE_CLASS.cpp  .generated_files/461d05f8500069f2122c69d49dece9602c111119.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48" -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DNDEBUG -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o  -o ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o ../SPI_SLAVE_CLASS.cpp  -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o: ../Zero_Cross_Counter.cpp  .generated_files/f0dcad0293d410971fe0f5c91ac479b96f2145b7.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48" -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DNDEBUG -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o  -o ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o ../Zero_Cross_Counter.cpp  -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  .generated_files/870dbffff563eb4ed2ad247ba32430b32020ef3b.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DNDEBUG -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/main.o.d" -MT "${OBJECTDIR}/_ext/1472/main.o.d" -MT ${OBJECTDIR}/_ext/1472/main.o  -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp  -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o: ../SPI_SLAVE_CLASS.cpp  .generated_files/1064683c310d735fd43c0a58c6ef994d3207d3fc.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DNDEBUG -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o  -o ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o ../SPI_SLAVE_CLASS.cpp  -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o: ../Zero_Cross_Counter.cpp  .generated_files/b797ea8ea5402d5325d9a7aca00e8162b3261c6f.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DNDEBUG -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o  -o ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o ../Zero_Cross_Counter.cpp  -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=avr128db48 -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"   -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,-lm -Wl,--end-group 
	
	${MP_CC_DIR}\\avr-objcopy -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.eep" || exit 0
	${MP_CC_DIR}\\avr-objdump -h -S "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" > "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.lss"
	${MP_CC_DIR}\\avr-objcopy -O srec -R .eeprom -R .fuse -R .lock -R .signature "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.srec"
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=avr128db48 -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_Release=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.hex"
	${MP_CC_DIR}\\avr-objcopy -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.eep" || exit 0
	${MP_CC_DIR}\\avr-objdump -h -S "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" > "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.lss"
	${MP_CC_DIR}\\avr-objcopy -O srec -R .eeprom -R .fuse -R .lock -R .signature "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.srec"
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} -r dist/Release

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
