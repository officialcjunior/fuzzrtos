#!/bin/sh

rm json.pb.cc json.pb.h
protoc ./json.proto --cpp_out=.