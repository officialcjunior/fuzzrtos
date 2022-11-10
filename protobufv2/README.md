# LibProtoBuf CoreJSON Fuzzer

## Dependencies

+ Install the following packages:
```
sudo apt-get update
sudo apt-get install protobuf-compiler libprotobuf-dev binutils cmake ninja-build liblzma-dev libz-dev pkg-config autoconf libtool
```
+ Install clang
+ Update clang, clang++ versions in the Makefile based on the versions installed.
+ Install libprotobuf-mutator - [follow this tutorial](https://github.com/google/libprotobuf-mutator/blob/master/README.md)
+ Update libprotobuf path in Makefile based on installation.

## Compilation and running

+ To update changes in `json.proto` (and generate `json.pb.cc`/`json.pb.h`) run `update-proto.sh`.
+ To compile and link the fuzz harness, run `make all`.
+ Run `./corejson_fuzz` to run the fuzzer.
