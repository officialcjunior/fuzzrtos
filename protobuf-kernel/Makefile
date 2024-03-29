# Changeable values
TARGET                := freertos_kernel_fuzz
C                     := clang-10
CXX                   := clang++-10
CXXFLAGS              := -g -fsanitize=fuzzer,address
PB_SRC                := rtos_protocol_buffers.pb.cc
PROTOBUF_DIR          := $(HOME)/libprotobuf-mutator/build/external.protobuf
LPM_DIR               := $(HOME)/libprotobuf-mutator
PROTOBUF_LIB          := $(PROTOBUF_DIR)/lib/libprotobufd.a
LPM_LIB               := $(LPM_DIR)/build/src/libfuzzer/libprotobuf-mutator-libfuzzer.a $(LPM_DIR)/build/src/libprotobuf-mutator.a
INC                   := -I$(PROTOBUF_DIR)/include -I$(LPM_DIR)
FUZZ_FLAGS            := -DLLVMFuzzerTestOneInput=fuzz
FREERTOS_FLAGS        := -DprojCOVERAGE_TEST=1 -DTRACE_ON_ENTER=0
LINKER_FLAGS          := -fuse-ld=mold -lpcap

FREERTOS_DIR_REL      := ./FreeRTOS/FreeRTOS
FREERTOS_DIR          := $(abspath $(FREERTOS_DIR_REL))

FREERTOS_PLUS_DIR_REL := ./FreeRTOS/FreeRTOS-Plus
FREERTOS_PLUS_DIR     := $(abspath $(FREERTOS_PLUS_DIR_REL))

KERNEL_DIR            := ${FREERTOS_DIR}/Source

INCLUDE_DIRS          := -I./posix
INCLUDE_DIRS          += -I./posix/Trace_Recorder_Configuration
INCLUDE_DIRS          += -I${KERNEL_DIR}/include
INCLUDE_DIRS          += -I${KERNEL_DIR}/portable/ThirdParty/GCC/Posix
INCLUDE_DIRS          += -I${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils
INCLUDE_DIRS          += -I${FREERTOS_DIR}/Demo/Common/include
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/Include
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/config
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/streamports/File/include
INCLUDE_DIRS          += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/streamports/File/config


# for freertos_ip.h
INCLUDE_DIRS += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/include/
# for rtosip (so, I think the freertosconfig being used is the one over here)
INCLUDE_DIRS += -I${FREERTOS_PLUS_DIR}/Demo/FreeRTOS_Plus_TCP_Echo_Posix
INCLUDE_DIRS += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/portable/Compiler/GCC/

# for the AF_NET not found errors
INCLUDE_DIRS += -I${FREERTOS_DIR}/Demo/Common/ethernet/lwIP/include/ipv4/lwip/

SOURCE_FILES          := $(wildcard ./posix/*.c)
SOURCE_FILES          += $(wildcard ${FREERTOS_DIR}/Source/*.c)
SOURCE_FILES          += ${KERNEL_DIR}/portable/MemMang/heap_3.c
SOURCE_FILES          += ${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c
SOURCE_FILES          += ${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/port.c
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
SOURCE_FILES          += ${FREERTOS_PLUS_DIR}/Demo/FreeRTOS_Plus_TCP_Echo_Posix/main_networking.c
SOURCE_FILES          += ${FREERTOS_PLUS_DIR}/Demo/FreeRTOS_Plus_TCP_Echo_Posix/TCPEchoClient_SingleTasks.c


SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_ARP.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_DHCP.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_DNS.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Cache.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Callback.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Networking.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_DNS_Parser.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_ICMP.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_IP.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_IP_Timers.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_IP_Utils.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_Sockets.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_Stream_Buffer.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_IP.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_Reception.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_State_Handling.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_Transmission.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_Utils.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_TCP_WIN.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_Tiny_TCP.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/FreeRTOS_UDP_IP.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/portable/BufferManagement/BufferAllocation_2.c
SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/source/portable/NetworkInterface/linux/NetworkInterface.c


OBJ_FILES = $(SOURCE_FILES:%.c=%.o)

DEP_FILE = $(OBJ_FILES:%.o=%.d)

-include ${DEP_FILE}
all: $(TARGET)

%.o : %.c Makefile
	$(C) $(CXXFLAGS) $(INCLUDE_DIRS) $(FREERTOS_FLAGS) -MMD -c $< -o $@

harness.o: harness.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(FREERTOS_FLAGS) -c $(FUZZ_FLAGS) $(PB_SRC) $(LPM_LIB) $(PROTOBUF_LIB) $(INC) $<

$(TARGET): harness.o $(OBJ_FILES) $(TARGET).cc
	$(CXX) $(CXXFLAGS) $(LINKER_FLAGS) -o $@ $^ $(PB_SRC) $(LPM_LIB) $(PROTOBUF_LIB) $(INC)

clean: 
	find . -type f -name '*.o' -delete
	find . -type f -name '*.d' -delete
	rm $(TARGET)
