

FREERTOS_DIR_REL      := ../../../FreeRTOS
FREERTOS_DIR          := $(abspath $(FREERTOS_DIR_REL))

FREERTOS_PLUS_DIR_REL := ../../../FreeRTOS-Plus
FREERTOS_PLUS_DIR     := $(abspath $(FREERTOS_PLUS_DIR_REL))

KERNEL_DIR            := ${FREERTOS_DIR}/Source

INCLUDE_DIRS          := -I.
INCLUDE_DIRS          += -I./Trace_Recorder_Configuration
INCLUDE_DIRS          += -I${KERNEL_DIR}/include
INCLUDE_DIRS          += -I${KERNEL_DIR}/portable/ThirdParty/GCC/Posix
INCLUDE_DIRS          += -I${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils
INCLUDE_DIRS          += -I${FREERTOS_DIR}/Demo/Common/include
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/Include
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/config
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/streamports/File/include
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/streamports/File/config

SOURCE_FILES          := $(wildcard *.c)
SOURCE_FILES          += $(wildcard ${FREERTOS_DIR}/Source/*.c)
# Memory manager (use malloc() / free() )
SOURCE_FILES          += ${KERNEL_DIR}/portable/MemMang/heap_3.c
# posix port
SOURCE_FILES          += ${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c
SOURCE_FILES          += ${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/port.c

# Demo library.
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/AbortDelay.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/BlockQ.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/blocktim.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/countsem.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/death.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/dynamic.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/EventGroupsDemo.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/flop.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/GenQTest.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/integer.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/IntSemTest.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/MessageBufferAMP.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/MessageBufferDemo.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/PollQ.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/QPeek.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/QueueOverwrite.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/QueueSet.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/QueueSetPolling.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/recmutex.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/semtest.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/StaticAllocation.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/StreamBufferDemo.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/StreamBufferInterrupt.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/TaskNotify.c
SOURCE_FILES          += ${FREERTOS_DIR}/Demo/Common/Minimal/TimerDemo.c

SOURCE_FILES          += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/trcKernelPort.c
SOURCE_FILES          += $(wildcard ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/*.c )

OBJ_FILES = $(SOURCE_FILES:%.c=%.o)

DEP_FILE = $(OBJ_FILES:%.o=%.d)


TARGET=corejson_fuzz
C=clang
CXX=clang++
CXXFLAGS=-g -fsanitize=fuzzer,address
PB_SRC=json.pb.cc
PWD=/home/cjunior/Downloads/arch

PROTOBUF_DIR=$(PWD)/libprotobuf-mutator/build/external.protobuf
LPM_DIR=$(PWD)/libprotobuf-mutator
PROTOBUF_LIB=$(PROTOBUF_DIR)/lib/libprotobufd.a
LPM_LIB=$(LPM_DIR)/build/src/libfuzzer/libprotobuf-mutator-libfuzzer.a $(LPM_DIR)/build/src/libprotobuf-mutator.a
INC=-I$(PROTOBUF_DIR)/include -I$(LPM_DIR)
DFUZZ=-DLLVMFuzzerTestOneInput=fuzz

all: $(TARGET)
-include ${DEP_FILE}

%.o : %.c Makefile
	$(C) $(CXXFLAGS) $(INCLUDE_DIRS) -DprojCOVERAGE_TEST=1 -DTRACE_ON_ENTER=0  -MMD -c $< -o $@

harness.o: harness.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -DprojCOVERAGE_TEST=1 -DTRACE_ON_ENTER=0  -c $(DFUZZ) $<

core_json.o: core_json.c
	$(C) $(CXXFLAGS) -c $<

$(TARGET): harness.o core_json.o $(OBJ_FILES) $(TARGET).cc
	$(CXX) $(CXXFLAGS) -o $@ $^ $(PB_SRC) $(LPM_LIB) $(PROTOBUF_LIB) $(INC)

clean: 
	rm $(TARGET) *.o
