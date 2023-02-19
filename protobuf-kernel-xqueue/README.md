## Setup

+ Clone, update only included submodules (FreeRTOS, FreeRTOS-Kernel)
+ FreeRTOS-Kernel Path is at `FreeRTOS/FreeRTOS/Source`
+ Before building, replace library paths in Makefile with your own

## TODO

+ Update proto file, rename to `kernel.proto` and regenerate source using `update_proto.sh`
+ Update `freertos_kernel_fuzz.cc` with serialization functions for kernel data structures
+ Update harness, call kernel functionality
