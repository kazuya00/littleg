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
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Actor.o \
	${OBJECTDIR}/EventDispatcher.o \
	${OBJECTDIR}/Drawable.o \
	${OBJECTDIR}/Texture.o \
	${OBJECTDIR}/Sprite.o \
	${OBJECTDIR}/Stage.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/ActorContactListener.o \
	${OBJECTDIR}/AnimatedTexture.o \
	${OBJECTDIR}/Little.o \
	${OBJECTDIR}/Event.o \
	${OBJECTDIR}/Resource.o \
	${OBJECTDIR}/Clip.o \
	${OBJECTDIR}/Object.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config sdl box2d gl glu --cflags --libs` -lSDL_image 
CXXFLAGS=`pkg-config sdl box2d gl glu --cflags --libs` -lSDL_image 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/littleengine2

dist/Debug/GNU-Linux-x86/littleengine2: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/littleengine2 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Actor.o: nbproject/Makefile-${CND_CONF}.mk Actor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Actor.o Actor.cpp

${OBJECTDIR}/EventDispatcher.o: nbproject/Makefile-${CND_CONF}.mk EventDispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/EventDispatcher.o EventDispatcher.cpp

${OBJECTDIR}/Drawable.o: nbproject/Makefile-${CND_CONF}.mk Drawable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Drawable.o Drawable.cpp

${OBJECTDIR}/Texture.o: nbproject/Makefile-${CND_CONF}.mk Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Texture.o Texture.cpp

${OBJECTDIR}/Sprite.o: nbproject/Makefile-${CND_CONF}.mk Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sprite.o Sprite.cpp

${OBJECTDIR}/Stage.o: nbproject/Makefile-${CND_CONF}.mk Stage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Stage.o Stage.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/ActorContactListener.o: nbproject/Makefile-${CND_CONF}.mk ActorContactListener.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ActorContactListener.o ActorContactListener.cpp

${OBJECTDIR}/AnimatedTexture.o: nbproject/Makefile-${CND_CONF}.mk AnimatedTexture.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/AnimatedTexture.o AnimatedTexture.cpp

${OBJECTDIR}/Little.o: nbproject/Makefile-${CND_CONF}.mk Little.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Little.o Little.cpp

${OBJECTDIR}/Event.o: nbproject/Makefile-${CND_CONF}.mk Event.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Event.o Event.cpp

${OBJECTDIR}/Resource.o: nbproject/Makefile-${CND_CONF}.mk Resource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Resource.o Resource.cpp

${OBJECTDIR}/Clip.o: nbproject/Makefile-${CND_CONF}.mk Clip.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Clip.o Clip.cpp

${OBJECTDIR}/Object.o: nbproject/Makefile-${CND_CONF}.mk Object.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Object.o Object.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/littleengine2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
