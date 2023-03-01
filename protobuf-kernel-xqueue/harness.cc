#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "queue.h"

// Fuzzer entrypoint
extern "C" int fuzz(char **data, int mode_len, size_t size) {

    QueueHandle_t xQueue;
    
    // Avoid crashes on nulls
    if(size < 1 || mode_len >= (size + 1)) {
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
            xQueue = xQueueCreate(mode_len, size);
            for(int i=0; i<mode_len; ++i) {
                xQueueSend(xQueue, ( void * ) data[i], ( TickType_t ) 0 );
                xQueueReceive(xQueue, ( void * ) data[i], 0);
            }
            free(xQueue);
        break;       

    }
    return 0;
}
