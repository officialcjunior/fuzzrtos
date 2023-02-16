#!/bin/sh

rm ./rtos-protocol-buffers.pb.cc ./rtos-protocol-buffers.pb.h
protoc ./rtos_protocol_buffers.proto --cpp_out=.
