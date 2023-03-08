#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "rtos_protocol_buffers.pb.h"
#include "freertos_kernel_fuzz.h"

#include <bits/stdc++.h>
#include <string>
#include <iostream>

#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"
#include "google/protobuf/util/delimited_message_util.h"

// Fuzzing entrypoint
extern "C" int fuzz(char *data, size_t size);

extern "C" int fuzz_tcp(const TcpMessage& tcp_pb);
extern "C" int fuzz_stream_buffer(char *data, size_t size);
extern "C" int fuzz_queue(char *data, size_t size);
extern "C" int fuzz_task(const Task& task_pb);
extern "C" int fuzz_semaphore(char *data, size_t size);
extern "C" int fuzz_event_group(const EventGroup& event_group_pb);
extern "C" int fuzz_mutex(const Mutex& mutex_pb);


DEFINE_PROTO_FUZZER(const input &input) {

    TcpMessage tcp_message;
    StreamBuffer stream_buffer;
    Queue queue;
    Task task;
    Semaphore semaphore;
    EventGroup event_group;
    Mutex mutex;
    
    std::string serialized_input;
    
    // Persistent fuzzing
    // Execute random functionality on each iteration
    for(int i = 0; i < input.seq_size(); ++i) {

        Option opt = input.seq(i);

        switch(opt.value_case()) {

            case Option::kStream:
                opt.SerializeToString(&serialized_input);
                fuzz_stream_buffer((char*)serialized_input.data(), serialized_input.size());
                break;

            case Option::kTcp:
                fuzz_tcp(opt.tcp());
                break;
            
            case Option::kQueue:
                opt.SerializeToString(&serialized_input);
                fuzz_queue((char*)serialized_input.data(), serialized_input.size());
                break;
            
            case Option::kTask:
                fuzz_task(opt.task());
                break;

            case Option::kSemaphore:
                opt.SerializeToString(&serialized_input);
                fuzz_semaphore((char*)serialized_input.data(), serialized_input.size());
                break;

            case Option::kEventGroup:
                fuzz_event_group(opt.event_group());
                break;
            
            case Option::kMutex:
                fuzz_mutex(opt.mutex());
                break;
        }

        serialized_input.clear();

    }
}