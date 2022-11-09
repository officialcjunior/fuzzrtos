#!/bin/sh

rm json.pb.cc json.pb.h
protoc ./json.proto --cpp_out=.
clang-10 -g -fsanitize=address,fuzzer core_json.c -c
make all