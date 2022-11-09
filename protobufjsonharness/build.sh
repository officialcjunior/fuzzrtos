#!/bin/bash

set -o errexit

echo "[*] Generating protobuf code"
protoc --cpp_out=. json.proto
protoc --cpp_out=. field_mask.proto
protoc --cpp_out=. core_json.proto

echo "[*] Building object files"
clang++ -I /usr/include/google/protobuf -I /usr/local/include/libprotobuf-mutator json_writer.cpp -g -c
clang++ -I /usr/include/google/protobuf -I /usr/local/include/libprotobuf-mutator json.pb.cc -g -c
clang++ -I /usr/include/google/protobuf -I /usr/local/include/libprotobuf-mutator harness_corejson_parse.cpp -g -c
clang++ -I /usr/include/google/protobuf -I /usr/local/include/libprotobuf-mutator core_json.pb.cc -g -c
clang++ -c libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.cc \
        -I /usr/local/include/libprotobuf-mutator
clang++ -c libprotobuf-mutator/src/libfuzzer/libfuzzer_mutator.cc \
        -I /usr/local/include/libprotobuf-mutator
clang++ -c harness_corejson_parse.cpp \
        -g -fsanitize=address \
        -I /usr/local/include/libprotobuf-mutator \

echo "[*] Linking executables"
clang++ harness_corejson_parse.o json_writer.o json.pb.o core_json.pb.o \
        libfuzzer_macro.o libfuzzer_mutator.o \
        -fsanitize=fuzzer -fsanitize=address \
        /usr/local/lib/libjq.a \
        -lonig -lprotobuf -lprotobuf-mutator \
        -L /usr/local/lib/ \
        -o fuzzer_core_json_pair

test -f fuzzer_core_json_pair && echo "[*] Build succeeded" || exit 1