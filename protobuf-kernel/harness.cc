#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

// Fuzzer entrypoint
extern "C" int fuzz(char *data, int mode_len, size_t size) {

    int a = data[0];
    

    return 0;
}
