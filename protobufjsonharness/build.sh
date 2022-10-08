#!/bin/bash

set -o errexit

echo "[*] Generating protobuf code"
protoc --cpp_out=. json.proto
protoc --cpp_out=. core_json.proto

echo "[*] Building object files"
clang++ json_writer.cpp -g -c
clang++ json.pb.cc -g -c
clang++ core_json_writer.cpp -g -c
clang++ core_json.pb.cc -g -c
clang++ -c /src/libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.cc \
        -I /usr/local/include/libprotobuf-mutator
clang++ -c /src/libprotobuf-mutator/src/libfuzzer/libfuzzer_mutator.cc \
        -I /usr/local/include/libprotobuf-mutator
clang++ -c harness_jq_pair.cpp \
        -g -fsanitize=address \
        -I /usr/local/include/libprotobuf-mutator

echo "[*] Linking executables"
clang++ harness_jq_pair.o json_writer.o json.pb.o core_json_writer.o core_json.pb.o \
        libfuzzer_macro.o libfuzzer_mutator.o \
        -fsanitize=fuzzer -fsanitize=address \
        /usr/local/lib/libjq.a \
        -lonig -lprotobuf -lprotobuf-mutator \
        -L /usr/local/lib/ \
        -o fuzzer_core_json_pair

test -f fuzzer_core_json_pair && echo "[*] Build succeeded" || exit 1