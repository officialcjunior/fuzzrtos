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
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_IP_Private.h"
#include "FreeRTOS_TCP_IP.h"

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

        case 2:
        Socket_t xSocket;
        struct freertos_sockaddr xBindAddress;

        xSocket = FreeRTOS_socket(FREERTOS_AF_INET, FREERTOS_SOCK_DGRAM, FREERTOS_IPPROTO_TCP);

        FreeRTOS_bind(xSocket, &xBindAddress, sizeof(xBindAddress));

        FreeRTOS_listen(xSocket, 5);
        break;

    }
return 0;
}
