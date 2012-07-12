#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/Initialize.o ${OBJECTDIR}/Tmr6Interrupt.o ${OBJECTDIR}/ADC1Interrupt.o ${OBJECTDIR}/Tmr5Interrupt.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/Initialize.o.d ${OBJECTDIR}/Tmr6Interrupt.o.d ${OBJECTDIR}/ADC1Interrupt.o.d ${OBJECTDIR}/Tmr5Interrupt.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/Initialize.o ${OBJECTDIR}/Tmr6Interrupt.o ${OBJECTDIR}/ADC1Interrupt.o ${OBJECTDIR}/Tmr5Interrupt.o


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ256GP710
MP_LINKER_FILE_OPTION=,-Tp33FJ256GP710.gld
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
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  
	
${OBJECTDIR}/Initialize.o: Initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Initialize.o.d 
	@${RM} ${OBJECTDIR}/Initialize.o.ok ${OBJECTDIR}/Initialize.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Initialize.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Initialize.o.d" -o ${OBJECTDIR}/Initialize.o Initialize.c  
	
${OBJECTDIR}/Tmr6Interrupt.o: Tmr6Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Tmr6Interrupt.o.d 
	@${RM} ${OBJECTDIR}/Tmr6Interrupt.o.ok ${OBJECTDIR}/Tmr6Interrupt.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Tmr6Interrupt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tmr6Interrupt.o.d" -o ${OBJECTDIR}/Tmr6Interrupt.o Tmr6Interrupt.c  
	
${OBJECTDIR}/ADC1Interrupt.o: ADC1Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ADC1Interrupt.o.d 
	@${RM} ${OBJECTDIR}/ADC1Interrupt.o.ok ${OBJECTDIR}/ADC1Interrupt.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ADC1Interrupt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ADC1Interrupt.o.d" -o ${OBJECTDIR}/ADC1Interrupt.o ADC1Interrupt.c  
	
${OBJECTDIR}/Tmr5Interrupt.o: Tmr5Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Tmr5Interrupt.o.d 
	@${RM} ${OBJECTDIR}/Tmr5Interrupt.o.ok ${OBJECTDIR}/Tmr5Interrupt.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Tmr5Interrupt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tmr5Interrupt.o.d" -o ${OBJECTDIR}/Tmr5Interrupt.o Tmr5Interrupt.c  
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  
	
${OBJECTDIR}/Initialize.o: Initialize.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Initialize.o.d 
	@${RM} ${OBJECTDIR}/Initialize.o.ok ${OBJECTDIR}/Initialize.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Initialize.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Initialize.o.d" -o ${OBJECTDIR}/Initialize.o Initialize.c  
	
${OBJECTDIR}/Tmr6Interrupt.o: Tmr6Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Tmr6Interrupt.o.d 
	@${RM} ${OBJECTDIR}/Tmr6Interrupt.o.ok ${OBJECTDIR}/Tmr6Interrupt.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Tmr6Interrupt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tmr6Interrupt.o.d" -o ${OBJECTDIR}/Tmr6Interrupt.o Tmr6Interrupt.c  
	
${OBJECTDIR}/ADC1Interrupt.o: ADC1Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ADC1Interrupt.o.d 
	@${RM} ${OBJECTDIR}/ADC1Interrupt.o.ok ${OBJECTDIR}/ADC1Interrupt.o.err 
	@${FIXDEPS} "${OBJECTDIR}/ADC1Interrupt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ADC1Interrupt.o.d" -o ${OBJECTDIR}/ADC1Interrupt.o ADC1Interrupt.c  
	
${OBJECTDIR}/Tmr5Interrupt.o: Tmr5Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Tmr5Interrupt.o.d 
	@${RM} ${OBJECTDIR}/Tmr5Interrupt.o.ok ${OBJECTDIR}/Tmr5Interrupt.o.err 
	@${FIXDEPS} "${OBJECTDIR}/Tmr5Interrupt.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tmr5Interrupt.o.d" -o ${OBJECTDIR}/Tmr5Interrupt.o Tmr5Interrupt.c  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  /home/jjmcd/Projects/PIC/dsPIC/LCDlib-Ex16.X/dist/default/production/LCDlib-Ex16.X.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   /home/jjmcd/Projects/PIC/dsPIC/LCDlib-Ex16.X/dist/default/production/LCDlib-Ex16.X.a    -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  /home/jjmcd/Projects/PIC/dsPIC/LCDlib-Ex16.X/dist/default/production/LCDlib-Ex16.X.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   /home/jjmcd/Projects/PIC/dsPIC/LCDlib-Ex16.X/dist/default/production/LCDlib-Ex16.X.a    -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}/pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Ex16-LCD-Ana.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
