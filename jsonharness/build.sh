#!/bin/sh

clang-10 -g -fsanitize=address,fuzzer -I coreJSON/source/include fuzz.c coreJSON/source/core_json.c -o fuzz
