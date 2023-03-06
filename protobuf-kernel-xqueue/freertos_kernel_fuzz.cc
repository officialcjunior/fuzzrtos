#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "rtos_protocol_buffers.pb.h"
#include "freertos_kernel_fuzz.h"

#include <bits/stdc++.h>
#include <string>

std::vector<const char*> SerializeQueue(const Queue_val &q_v) {
    std::vector<const char*> arr;
    for(int i=0; i<q_v.a_size(); ++i) {
        arr.push_back(q_v.a(i).str().c_str());
    }
    return arr;
}

// Fuzzing entrypoint
extern "C" int fuzz(std::vector<const char*> data, size_t mode_len, size_t size);

DEFINE_PROTO_FUZZER(const Queue_val &q_v) {
    
    std::vector<const char*> s = SerializeQueue(q_v);

    fuzz(s, q_v.a_size(), sizeof(q_v.a(0).str().c_str()));
}
