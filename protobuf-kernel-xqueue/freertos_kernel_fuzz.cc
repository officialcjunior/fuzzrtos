#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "rtos_protocol_buffers.pb.h"
#include "freertos_kernel_fuzz.h"

#include <bits/stdc++.h>
#include <string>

std::vector<std::string> SerializeQueue(Queue_val &q_v) {
    std::vector<std::string> arr;
    for(int i=0; i<q_v.a_size(); ++i) {
        arr.push_back(q_v.a(i).str().c_str());
    }
    return arr;
}

// Fuzzing entrypoint
extern "C" int fuzz(std::vector<std::string> data, size_t mode_len, size_t size);

DEFINE_PROTO_FUZZER(const Queue_val &q_v) {
    
    std::vector<std::string> s = SerializeQueue(q_v);

    fuzz(s, q_v.a_size(), sizeof(q_v.a(0).str()));
}
