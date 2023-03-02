#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "rtos_protocol_buffers.pb.h"
#include "freertos_kernel_fuzz.h"

#include <bits/stdc++.h>
#include <string>
#include <iostream>

#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"
#include "google/protobuf/util/delimited_message_util.h"

std::string SerializeStreambuffer(const StreamBuffer &test_proto) {
    std::stringstream all;
    const auto &aa = test_proto.a();
    const auto &bb = test_proto.b();
    all.write((const char*)&aa, sizeof(aa));
    if(bb.size() != 0) {
        all.write(bb.c_str(), bb.size());
    }

    std::string res = all.str();
    return res;
}

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

    //std::cout << test_proto.DebugString() << "Fuzzing protobuf-kernel";
    //std::string s = SerializeStreambuffer(test_proto);

    TcpMessage tcp_message;
    StreamBuffer stream_buffer;
    Queue queue;
    Task task;
    Semaphore semaphore;
    EventGroup event_group;
    Mutex mutex;
    
    std::string serialized_input;
    if (input.has_stream()) {
        input.SerializeToString(&serialized_input);
        fuzz_stream_buffer((char*)serialized_input.data(), serialized_input.size());
    } else if (input.has_tcp()) {
        fuzz_tcp(input.tcp());
    } else if (input.has_queue()) {
        input.SerializeToString(&serialized_input);
        fuzz_queue((char*)serialized_input.data(), serialized_input.size());
    } else if (input.has_task()) {
        fuzz_task(input.task());
    } else if (input.has_semaphore()) {
        input.SerializeToString(&serialized_input);
        fuzz_semaphore((char*)serialized_input.data(), serialized_input.size());
    } else if (input.has_event_group()) {
        fuzz_event_group(input.event_group());
    } else if (input.has_mutex()) {
        fuzz_mutex(input.mutex());
    }
}

/*
std::string SerializeStreamBuffer(const StreamBuffer& message) {
    std::stringstream ss;
    google::protobuf::util::SerializeDelimitedToOstream(message, &ss);
    std::string serialized_message = ss.str();
    return serialized_message;
}

// Serialize TcpMessage to a binary string
std::string SerializeTcpMessage(const TcpMessage& message) {
    std::stringstream ss;
    google::protobuf::util::SerializeDelimitedToOstream(message, &ss);
    std::string serialized_message = ss.str();
    return serialized_message;
}

// Deserialize StreamBuffer from a binary string
bool DeserializeStreamBuffer(const std::string& input, StreamBuffer* message) {
  google::protobuf::io::ArrayInputStream input_stream(input.data(), input.size());
  return google::protobuf::util::ParseDelimitedFromZeroCopyStream(message, &input_stream, nullptr);
}

// Deserialize TcpMessage from a binary string
bool DeserializeTcpMessage(const std::string& input, TcpMessage* message) {
  google::protobuf::io::ArrayInputStream input_stream(input.data(), input.size());
  return google::protobuf::util::ParseDelimitedFromZeroCopyStream(message, &input_stream, nullptr);
} */
