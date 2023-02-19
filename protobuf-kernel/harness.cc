#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "stream_buffer.h"
#include "queue.h"
#include "timers.h"

// Fuzzer entrypoint
extern "C" int fuzz(char *data, size_t size) {

    static StreamBufferHandle_t buffer;
    static QueueHandle_t queue;
    static TimerHandle_t xTimer;

    // First bit determines structure to fuzz
    switch(data[0] % 2) {
        
        // streambuffer
        case 0:
            buffer = xStreamBufferCreate(100, 1);
            xStreamBufferSend(buffer, data, size, portMAX_DELAY);
            xStreamBufferReceive(buffer, data, size, portMAX_DELAY);            
            free(buffer);
            break;

        // queue
        case 1:
            queue = xQueueGenericCreate(size, 1, 0);
            xQueueSend(queue, data, portMAX_DELAY);
            xQueueReceive(queue, data, portMAX_DELAY);
            free(queue);
            break;
    
    }

    return 0;
}
