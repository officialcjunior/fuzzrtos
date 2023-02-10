#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "rtos_protocol_buffers.pb.h"
#include "freertos_kernel_fuzz.h"

#include <bits/stdc++.h>
#include <string>

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
extern "C" int fuzz(char *data, size_t mode_len, size_t size);

DEFINE_PROTO_FUZZER(const StreamBuffer &test_proto) {
    
    std::string s = SerializeStreambuffer(test_proto);

    fuzz((char*)s.data(), s.length(), s.size());
}
