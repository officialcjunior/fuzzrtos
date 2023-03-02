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
#include "rtos_protocol_buffers.pb.h"

/* Fuzzer entrypoint
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

        int32_t iReturned;
        struct freertos_sockaddr xDestinationAddress;
        xDestinationAddress.sin_addr = FreeRTOS_inet_addr_quick( 192, 168, 0, 100 );
        xDestinationAddress.sin_port = FreeRTOS_htons( 1024 );

         iReturned = FreeRTOS_sendto(
                                    xSocket,
                                    data,
                                    128,
                                    0,
                                    &xDestinationAddress,
                                    sizeof( xDestinationAddress )
                               );
        break;

    }
return 0;
} */

extern "C" int fuzz_tcp(const TcpMessage& tcp_pb) {
    switch (tcp_pb.id()) {
        case 1: {
            Socket_t xSocket;
            struct freertos_sockaddr xBindAddress;

            xSocket = FreeRTOS_socket(FREERTOS_AF_INET, FREERTOS_SOCK_DGRAM, FREERTOS_IPPROTO_TCP);

            FreeRTOS_bind(xSocket, &xBindAddress, sizeof(xBindAddress));

            FreeRTOS_listen(xSocket, 5);

            int32_t iReturned;
            struct freertos_sockaddr xDestinationAddress;
            xDestinationAddress.sin_addr = FreeRTOS_inet_addr_quick( 192, 168, 0, 100 );
            xDestinationAddress.sin_port = FreeRTOS_htons( 1024 );

            iReturned = FreeRTOS_sendto(
                                        xSocket,
                                        tcp_pb.payload().c_str(),
                                        128,
                                        0,
                                        &xDestinationAddress,
                                        sizeof( xDestinationAddress )
                                );
            break;
        }
        case 2: {

        }
    }
    return 0;
}

extern "C" int fuzz_stream_buffer(char *data, size_t size) {
    static StreamBufferHandle_t buffer;
    buffer = xStreamBufferCreate(100, 1);
    xStreamBufferSend(buffer, data, size, portMAX_DELAY);
    xStreamBufferReceive(buffer, data, size, portMAX_DELAY);            
    free(buffer);
    return 0;
}

extern "C" int fuzz_queue(char *data, size_t size) {
    static QueueHandle_t queue;
    queue = xQueueGenericCreate(size, 1, 0);
    xQueueSend(queue, data, portMAX_DELAY);
    xQueueReceive(queue, data, portMAX_DELAY);
    free(queue);
    return 0;
}


void example_task( void * pvParameters )
{
    // The parameter value is expected to be 1 as 1 is passed in the
    // pvParameters value in the call to xTaskCreate() below. 
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    for( ;; )
    {
        /* Task code goes here. */
    }
}
extern "C" int fuzz_task(const Task& task_pb) {
    TaskHandle_t task_handle;
    xTaskCreate(example_task, task_pb.name().c_str(), task_pb.stack_size(), nullptr, task_pb.priority(), &task_handle);
    return 0;
}

extern "C" int fuzz_semaphore(char *data, size_t size) {
    static SemaphoreHandle_t semaphore;
    semaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(semaphore);
    xSemaphoreTake(semaphore, portMAX_DELAY);
    free(semaphore);
    return 0;
}

extern "C" int fuzz_event_group(const EventGroup& event_group_pb) {
  EventGroupHandle_t event_group_handle = xEventGroupCreate();
  // both of these cause a compilaion error
  //vEventGroupSetBits(event_group_handle, event_group_pb.event_bits());
  //vEventGroupClearBits(event_group_handle, event_group_pb.event_bits());
  vEventGroupDelete(event_group_handle);
  return 0;
}

// pretty much useless
extern "C" int fuzz_mutex(const Mutex& mutex_pb) {
  SemaphoreHandle_t mutex_handle = xSemaphoreCreateMutex();
  xSemaphoreGive(mutex_handle);
  xSemaphoreTake(mutex_handle, portMAX_DELAY);
    return 0;
}