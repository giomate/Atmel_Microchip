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
ifeq "$(wildcard nbproject/Makefile-local-test_app.mk)" "nbproject/Makefile-local-test_app.mk"
include nbproject/Makefile-local-test_app.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=test_app
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
	${MAKE}  -f nbproject/Makefile-test_app.mk dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  .generated_files/e9bd7d0b3395d5db93cea0077ffc86e28fa2e390.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48" -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DDEBUG -I "../../../AVR128DB_BSP/AVR128DB_BSP/examples/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils/assembler" -I "../../../AVR128DB_BSP/AVR128DB_BSP/src" -I "../../../AVR128DB_BSP/AVR128DB_BSP/" -I "../../../AVR128DB_BSP/AVR128DB_BSP/Config" -I ".." -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/main.o.d" -MT "${OBJECTDIR}/_ext/1472/main.o.d" -MT ${OBJECTDIR}/_ext/1472/main.o  -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -g2
	
${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o: ../SPI_SLAVE_CLASS.cpp  .generated_files/8a7001517f44278b7110db27eb191de509a2a124.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48" -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DDEBUG -I "../../../AVR128DB_BSP/AVR128DB_BSP/examples/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils/assembler" -I "../../../AVR128DB_BSP/AVR128DB_BSP/src" -I "../../../AVR128DB_BSP/AVR128DB_BSP/" -I "../../../AVR128DB_BSP/AVR128DB_BSP/Config" -I ".." -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o  -o ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o ../SPI_SLAVE_CLASS.cpp  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -g2
	
${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o: ../Zero_Cross_Counter.cpp  .generated_files/4bc1fadfc9ffabf3f33e53f6b868495b65967f85.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48" -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DDEBUG -I "../../../AVR128DB_BSP/AVR128DB_BSP/examples/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils/assembler" -I "../../../AVR128DB_BSP/AVR128DB_BSP/src" -I "../../../AVR128DB_BSP/AVR128DB_BSP/" -I "../../../AVR128DB_BSP/AVR128DB_BSP/Config" -I ".." -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o  -o ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o ../Zero_Cross_Counter.cpp  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -g2
	
else
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  .generated_files/72303f700cad60f35a86692558c773b09cd0af74.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DDEBUG -I "../../../AVR128DB_BSP/AVR128DB_BSP/examples/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils/assembler" -I "../../../AVR128DB_BSP/AVR128DB_BSP/src" -I "../../../AVR128DB_BSP/AVR128DB_BSP/" -I "../../../AVR128DB_BSP/AVR128DB_BSP/Config" -I ".." -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/main.o.d" -MT "${OBJECTDIR}/_ext/1472/main.o.d" -MT ${OBJECTDIR}/_ext/1472/main.o  -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -g2
	
${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o: ../SPI_SLAVE_CLASS.cpp  .generated_files/41ff339f23939979f147188e7f09270ab3195d66.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DDEBUG -I "../../../AVR128DB_BSP/AVR128DB_BSP/examples/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils/assembler" -I "../../../AVR128DB_BSP/AVR128DB_BSP/src" -I "../../../AVR128DB_BSP/AVR128DB_BSP/" -I "../../../AVR128DB_BSP/AVR128DB_BSP/Config" -I ".." -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT "${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o.d" -MT ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o  -o ${OBJECTDIR}/_ext/1472/SPI_SLAVE_CLASS.o ../SPI_SLAVE_CLASS.cpp  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -g2
	
${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o: ../Zero_Cross_Counter.cpp  .generated_files/934f33ce23eaeefe79fcbe60bb019faed04b640c.flag .generated_files/99534fa8ae220d0c451289ac177b99ce58384f5a.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=avr128db48  -I "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/include" -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -DDEBUG -I "../../../AVR128DB_BSP/AVR128DB_BSP/examples/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/include" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils" -I "../../../AVR128DB_BSP/AVR128DB_BSP/utils/assembler" -I "../../../AVR128DB_BSP/AVR128DB_BSP/src" -I "../../../AVR128DB_BSP/AVR128DB_BSP/" -I "../../../AVR128DB_BSP/AVR128DB_BSP/Config" -I ".." -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT "${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o.d" -MT ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o  -o ${OBJECTDIR}/_ext/1472/Zero_Cross_Counter.o ../Zero_Cross_Counter.cpp  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -g2
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../AVR128DB_BSP/AVR128DB_BSP/AVR128DB_BSP.X/dist/Debug/debug/AVR128DB_BSP.X.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=avr128db48 -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"   -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\AVR128DB_BSP\AVR128DB_BSP\AVR128DB_BSP.X\dist\Debug\debug\AVR128DB_BSP.X.a  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,-lm -Wl,--end-group 
	
	${MP_CC_DIR}\\avr-objcopy -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.eep" || exit 0
	${MP_CC_DIR}\\avr-objdump -h -S "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" > "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.lss"
	${MP_CC_DIR}\\avr-objcopy -O srec -R .eeprom -R .fuse -R .lock -R .signature "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.srec"
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../AVR128DB_BSP/AVR128DB_BSP/AVR128DB_BSP.X/dist/Debug/production/AVR128DB_BSP.X.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE) -mmcu=avr128db48 -B "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/Atmel/AVR-Dx_DFP/1.7.85/gcc/dev/avr128db48"  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist\${CND_CONF}\${IMAGE_TYPE}\Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\AVR128DB_BSP\AVR128DB_BSP\AVR128DB_BSP.X\dist\Debug\production\AVR128DB_BSP.X.a  -DXPRJ_test_app=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.hex"
	${MP_CC_DIR}\\avr-objcopy -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.eep" || exit 0
	${MP_CC_DIR}\\avr-objdump -h -S "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" > "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.lss"
	${MP_CC_DIR}\\avr-objcopy -O srec -R .eeprom -R .fuse -R .lock -R .signature "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/Zero_Cross_Detector_lib.X.${IMAGE_TYPE}.srec"
	
	
endif


# Subprojects
.build-subprojects:
	cd ../../../AVR128DB_BSP/AVR128DB_BSP/AVR128DB_BSP.X && ${MAKE}  -f Makefile CONF=Debug


# Subprojects
.clean-subprojects:
	cd ../../../AVR128DB_BSP/AVR128DB_BSP/AVR128DB_BSP.X && rm -rf "build/Debug" "dist/Debug"

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/test_app
	${RM} -r dist/test_app

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
