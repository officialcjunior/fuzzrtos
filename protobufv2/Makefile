TARGET=corejson_fuzz
CXX=clang++-10
CXXFLAGS=-g -fsanitize=fuzzer,address
PB_SRC=json.pb.cc

PROTOBUF_DIR=$(HOME)/libprotobuf-mutator/build/external.protobuf
LPM_DIR=$(HOME)/libprotobuf-mutator
PROTOBUF_LIB=$(PROTOBUF_DIR)/lib/libprotobufd.a
LPM_LIB=$(LPM_DIR)/build/src/libfuzzer/libprotobuf-mutator-libfuzzer.a $(LPM_DIR)/build/src/libprotobuf-mutator.a
INC=-I$(PROTOBUF_DIR)/include -I$(LPM_DIR)
DFUZZ=-DLLVMFuzzerTestOneInput=fuzz

all: $(TARGET)

harness.o: harness.cc
	$(CXX) $(CXXFLAGS) -c $(DFUZZ) $<

$(TARGET): harness.o core_json.o $(TARGET).cc
	$(CXX) $(CXXFLAGS) -o $@ $^ $(PB_SRC) $(LPM_LIB) $(PROTOBUF_LIB) $(INC)

clean: 
	rm $(TARGET) *.o
