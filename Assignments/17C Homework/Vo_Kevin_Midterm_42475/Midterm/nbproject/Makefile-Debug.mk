#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Prob10_PowerFunct.o \
	${OBJECTDIR}/Prob12_MutualRecursion.o \
	${OBJECTDIR}/Prob13_Set_Map.o \
	${OBJECTDIR}/Prob1_LinearBinary.o \
	${OBJECTDIR}/Prob2_Bubble_Selection_Sort.o \
	${OBJECTDIR}/Prob8_Dices.o \
	${OBJECTDIR}/Prob9_BitVector.o \
	${OBJECTDIR}/Prob_11.o \
	${OBJECTDIR}/Prob_3_ALL_3_SimpleVectors.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/prob7_Fib.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/midterm.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/midterm.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/midterm ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Prob10_PowerFunct.o: Prob10_PowerFunct.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob10_PowerFunct.o Prob10_PowerFunct.cpp

${OBJECTDIR}/Prob12_MutualRecursion.o: Prob12_MutualRecursion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob12_MutualRecursion.o Prob12_MutualRecursion.cpp

${OBJECTDIR}/Prob13_Set_Map.o: Prob13_Set_Map.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob13_Set_Map.o Prob13_Set_Map.cpp

${OBJECTDIR}/Prob1_LinearBinary.o: Prob1_LinearBinary.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob1_LinearBinary.o Prob1_LinearBinary.cpp

${OBJECTDIR}/Prob2_Bubble_Selection_Sort.o: Prob2_Bubble_Selection_Sort.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob2_Bubble_Selection_Sort.o Prob2_Bubble_Selection_Sort.cpp

${OBJECTDIR}/Prob8_Dices.o: Prob8_Dices.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob8_Dices.o Prob8_Dices.cpp

${OBJECTDIR}/Prob9_BitVector.o: Prob9_BitVector.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob9_BitVector.o Prob9_BitVector.cpp

${OBJECTDIR}/Prob_11.o: Prob_11.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob_11.o Prob_11.cpp

${OBJECTDIR}/Prob_3_ALL_3_SimpleVectors.o: Prob_3_ALL_3_SimpleVectors.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Prob_3_ALL_3_SimpleVectors.o Prob_3_ALL_3_SimpleVectors.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/prob7_Fib.o: prob7_Fib.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/prob7_Fib.o prob7_Fib.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
