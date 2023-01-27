# Changeable values
TARGET                := corejson_fuzz
C                     := clang-10
CXX                   := clang++-10
CXXFLAGS              := -g -fsanitize=fuzzer,address
PB_SRC                := json.pb.cc
PROTOBUF_DIR          := $(HOME)/libprotobuf-mutator/build/external.protobuf
LPM_DIR               := $(HOME)/libprotobuf-mutator
PROTOBUF_LIB          := $(PROTOBUF_DIR)/lib/libprotobufd.a
LPM_LIB               := $(LPM_DIR)/build/src/libfuzzer/libprotobuf-mutator-libfuzzer.a $(LPM_DIR)/build/src/libprotobuf-mutator.a
INC                   := -I$(PROTOBUF_DIR)/include -I$(LPM_DIR)
FUZZ_FLAGS            := -DLLVMFuzzerTestOneInput=fuzz
FREERTOS_FLAGS        := -DprojCOVERAGE_TEST=1 -DTRACE_ON_ENTER=0
LINKER_FLAGS          := -fuse-ld=mold

all: $(TARGET)

harness.o: harness.cc
	$(CXX) $(CXXFLAGS) -c $(FUZZ_FLAGS) $<

core_json.o: core_json.c
	$(C) $(CXXFLAGS) $(COV_FLAGS) -c $<

$(TARGET): harness.o core_json.o $(TARGET).cc
	$(CXX) $(CXXFLAGS) $(LINKER_FLAGS) $(COV_FLAGS) -o $@ $^ $(PB_SRC) $(LPM_LIB) $(PROTOBUF_LIB) $(INC)

clean: 
	rm $(TARGET) *.o
