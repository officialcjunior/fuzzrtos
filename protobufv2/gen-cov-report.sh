#!/bin/sh

LLVM_COV=llvm-cov-10

$LLVM_COV gcov -b core_json.gcda
gcovr -v -g . --html --html-details -o report.html