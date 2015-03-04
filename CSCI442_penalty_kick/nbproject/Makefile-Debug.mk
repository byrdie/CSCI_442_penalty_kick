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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-Lnaoqi_sdk/lib `pkg-config --libs opencv` -lQtCore -lQtGui -lQtMultimedia -lQtNetwork -lQtXml -lalaudio -lalbehavior -lalbehaviorinfo -lalbehaviormanager -lalbonjourdiscovery -lalboxlibrary -lalcommon -lalerror -lalextractor -lalfile -lallauncher -lallogremote -lalmath -lalmathinternal -lalmemoryfastaccess -lalmodelutils -lalmotionrecorder -lalparammanager -lalproject -lalproxies -lalpythontools -lalremotecall -lalresource -lalserial -lalsoap -lalthread -laltools -laltts -lalvalue -lalvalueconvert -lalvision -larchive -lavahi-client -lavahi-common -lavahi-core -lbn-common -lbn-i2c -lbn-ps -lbn-rt -lbn-spy -lbn-usb -lbn-version -lbn-xml -lboost_date_time-mt -lboost_filesystem-mt -lboost_locale-mt -lboost_prg_exec_monitor-mt -lboost_program_options-mt -lboost_regex-mt -lboost_serialization-mt -lboost_signals-mt -lboost_system-mt -lboost_thread-mt -lboost_timer-mt -lboost_wserialization-mt -ldcm_plugins -ldepthodometer -lellipsedetector -lellipsefitter -lhal_common -lhal_core -lio-rs232 -lio-rs485 -lio-usb -lio_headi2c -lio_headusb -lkpextract -llaser_utils -llib_dcm -llocalnavigation -llocalnavigation_debug -llogodetector -lmetrical -lnao-modules -lnao_devices -lnao_running -lnaointerface -lnaosensorutils -lnaosimulation_interface -lnaospecialsimulation_running -lnavcommon -lpathsimplifier -lplugin-initromeoheaddevices -lplugin_actuatorifnostiffness -lplugin_actuatorifnostiffnessromeo -lplugin_addnaodevicesspecialsimulation -lplugin_almemory -lplugin_calibration -lplugin_clientsync -lplugin_debugromeo -lplugin_differentialjointlimitation -lplugin_eyescontrolloop -lplugin_fsrtotalcenterofpression -lplugin_initTestBenchDevice -lplugin_initfromxml -lplugin_initmotorboard -lplugin_initnaodevices -lplugin_initromeodevices -lplugin_initromeomotorboard -lplugin_iocommunication -lplugin_ledifnodcm -lplugin_maxcurrent -lplugin_motortemperature -lplugin_motortojoint -lplugin_naoavailabledevice -lplugin_naospecial -lplugin_preferences -lplugin_resendConfigurationToCard -lplugin_security-romeo -lplugin_simulation -lplugin_simulation_fill_attributes -lplugin_simulation_fill_attributes_romeo -lplugin_specialjointlimitation -lplugin_test-romeo -lplugin_test -lplugin_testrobotversion -lplugin_timedcommand -lplugin_virtualdeviceromeo -lpointsearcher -lposture -lposturedetector -lposturegraph -lposturemanager -lpython2.7 -lqi -lqiproject-qt -lqiproject -lqpoases -lqpoasesfloat -lransacutils -lrobot -lrobot_devices -lromeo-modules -lromeo_devices -lromeo_head_running -lromeo_running -lrttools -lscanmatching -ltinyxml -ltoposlam -luuid naoqi_sdk/lib/_allog.so naoqi_sdk/lib/_almath.so naoqi_sdk/lib/_inaoqi.so naoqi_sdk/lib/_scanmatchingwrap.so  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick: naoqi_sdk/lib/_allog.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick: naoqi_sdk/lib/_almath.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick: naoqi_sdk/lib/_inaoqi.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick: naoqi_sdk/lib/_scanmatchingwrap.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Inaoqi_sdk/include `pkg-config --cflags opencv`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/csci442_penalty_kick

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
