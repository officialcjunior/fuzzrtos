#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "rtos_protocol_buffers.pb.h"
#include "freertos_kernel_fuzz.h"

#include <bits/stdc++.h>
#include <string>

std::string SerializeStreambuffer(Queue_val q_v) {
    std::stringstream all;
    all << "[";
    for(int i=0; i<q_v.item_size(); ++i) {
        all << q_v.a(i).value().str();
        if (i < q_v.items_size() - 1) {
            all << ", ";
        }
    }
    all << "]";
    std::string res = all.str();
    return res;
}

// Fuzzing entrypoint
extern "C" int fuzz(char *data, size_t mode_len, size_t size);

DEFINE_PROTO_FUZZER(const StreamBuffer &test_proto) {
    
    std::string s = SerializeStreambuffer(test_proto);

    fuzz((char*)s.data(), s.length(), s.size());
}
