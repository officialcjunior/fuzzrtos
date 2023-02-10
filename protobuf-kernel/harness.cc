#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "stream_buffer.h"

// Fuzzer entrypoint
extern "C" int fuzz(char *data, int mode_len, size_t size) {


    static StreamBufferHandle_t buffer;

    // Avoid crashes on nulls
    if(size < 2 || mode_len >= (size + 1)) {
        return 0;
    }

    switch(mode_len) {

        // Only validate
        case 0:
            //buffer = data;
           // bufferLength = sizeof(buffer) - 1;
            
           // xQueueGenericCreate( mode_len, mode_len, size );
            break;
        
        // Validate and search
        default:


            buffer = xStreamBufferCreate(100, 1);
            xStreamBufferSend(buffer, data, mode_len, portMAX_DELAY);
            xStreamBufferReceive(buffer, data, mode_len, portMAX_DELAY);            
            free(buffer);
        break;       

    }
    return 0;
}
