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
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCDlib-Ex16.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCDlib-Ex16.X.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/delay.o ${OBJECTDIR}/LCDcommand.o ${OBJECTDIR}/LCDcountedstring.o ${OBJECTDIR}/LCDinit.o ${OBJECTDIR}/LCDletter.o ${OBJECTDIR}/LCDputs.o ${OBJECTDIR}/LCDpulseEnableBit.o
POSSIBLE_DEPFILES=${OBJECTDIR}/delay.o.d ${OBJECTDIR}/LCDcommand.o.d ${OBJECTDIR}/LCDcountedstring.o.d ${OBJECTDIR}/LCDinit.o.d ${OBJECTDIR}/LCDletter.o.d ${OBJECTDIR}/LCDputs.o.d ${OBJECTDIR}/LCDpulseEnableBit.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/delay.o ${OBJECTDIR}/LCDcommand.o ${OBJECTDIR}/LCDcountedstring.o ${OBJECTDIR}/LCDinit.o ${OBJECTDIR}/LCDletter.o ${OBJECTDIR}/LCDputs.o ${OBJECTDIR}/LCDpulseEnableBit.o


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/LCDlib-Ex16.X.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o.ok ${OBJECTDIR}/delay.o.err 
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c  
	
${OBJECTDIR}/LCDcommand.o: LCDcommand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDcommand.o.d 
	@${RM} ${OBJECTDIR}/LCDcommand.o.ok ${OBJECTDIR}/LCDcommand.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDcommand.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDcommand.o.d" -o ${OBJECTDIR}/LCDcommand.o LCDcommand.c  
	
${OBJECTDIR}/LCDcountedstring.o: LCDcountedstring.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDcountedstring.o.d 
	@${RM} ${OBJECTDIR}/LCDcountedstring.o.ok ${OBJECTDIR}/LCDcountedstring.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDcountedstring.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDcountedstring.o.d" -o ${OBJECTDIR}/LCDcountedstring.o LCDcountedstring.c  
	
${OBJECTDIR}/LCDinit.o: LCDinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDinit.o.d 
	@${RM} ${OBJECTDIR}/LCDinit.o.ok ${OBJECTDIR}/LCDinit.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDinit.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDinit.o.d" -o ${OBJECTDIR}/LCDinit.o LCDinit.c  
	
${OBJECTDIR}/LCDletter.o: LCDletter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDletter.o.d 
	@${RM} ${OBJECTDIR}/LCDletter.o.ok ${OBJECTDIR}/LCDletter.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDletter.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDletter.o.d" -o ${OBJECTDIR}/LCDletter.o LCDletter.c  
	
${OBJECTDIR}/LCDputs.o: LCDputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDputs.o.d 
	@${RM} ${OBJECTDIR}/LCDputs.o.ok ${OBJECTDIR}/LCDputs.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDputs.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDputs.o.d" -o ${OBJECTDIR}/LCDputs.o LCDputs.c  
	
${OBJECTDIR}/LCDpulseEnableBit.o: LCDpulseEnableBit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDpulseEnableBit.o.d 
	@${RM} ${OBJECTDIR}/LCDpulseEnableBit.o.ok ${OBJECTDIR}/LCDpulseEnableBit.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDpulseEnableBit.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDpulseEnableBit.o.d" -o ${OBJECTDIR}/LCDpulseEnableBit.o LCDpulseEnableBit.c  
	
else
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o.ok ${OBJECTDIR}/delay.o.err 
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c  
	
${OBJECTDIR}/LCDcommand.o: LCDcommand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDcommand.o.d 
	@${RM} ${OBJECTDIR}/LCDcommand.o.ok ${OBJECTDIR}/LCDcommand.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDcommand.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDcommand.o.d" -o ${OBJECTDIR}/LCDcommand.o LCDcommand.c  
	
${OBJECTDIR}/LCDcountedstring.o: LCDcountedstring.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDcountedstring.o.d 
	@${RM} ${OBJECTDIR}/LCDcountedstring.o.ok ${OBJECTDIR}/LCDcountedstring.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDcountedstring.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDcountedstring.o.d" -o ${OBJECTDIR}/LCDcountedstring.o LCDcountedstring.c  
	
${OBJECTDIR}/LCDinit.o: LCDinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDinit.o.d 
	@${RM} ${OBJECTDIR}/LCDinit.o.ok ${OBJECTDIR}/LCDinit.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDinit.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDinit.o.d" -o ${OBJECTDIR}/LCDinit.o LCDinit.c  
	
${OBJECTDIR}/LCDletter.o: LCDletter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDletter.o.d 
	@${RM} ${OBJECTDIR}/LCDletter.o.ok ${OBJECTDIR}/LCDletter.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDletter.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDletter.o.d" -o ${OBJECTDIR}/LCDletter.o LCDletter.c  
	
${OBJECTDIR}/LCDputs.o: LCDputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDputs.o.d 
	@${RM} ${OBJECTDIR}/LCDputs.o.ok ${OBJECTDIR}/LCDputs.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDputs.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDputs.o.d" -o ${OBJECTDIR}/LCDputs.o LCDputs.c  
	
${OBJECTDIR}/LCDpulseEnableBit.o: LCDpulseEnableBit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDpulseEnableBit.o.d 
	@${RM} ${OBJECTDIR}/LCDpulseEnableBit.o.ok ${OBJECTDIR}/LCDpulseEnableBit.o.err 
	@${FIXDEPS} "${OBJECTDIR}/LCDpulseEnableBit.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDpulseEnableBit.o.d" -o ${OBJECTDIR}/LCDpulseEnableBit.o LCDpulseEnableBit.c  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/LCDlib-Ex16.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} -omf=elf $(MP_EXTRA_AR_PRE) r dist/${CND_CONF}/${IMAGE_TYPE}/LCDlib-Ex16.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
else
dist/${CND_CONF}/${IMAGE_TYPE}/LCDlib-Ex16.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_AR} -omf=elf $(MP_EXTRA_AR_PRE) r dist/${CND_CONF}/${IMAGE_TYPE}/LCDlib-Ex16.X.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    
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
