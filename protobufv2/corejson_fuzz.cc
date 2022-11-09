#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "json.pb.h"
#include "corejson_fuzz.h"

#include <bits/stdc++.h>
#include <string>

// Convert array to string
std::string JSON_arr_to_str(JSON_array arr) {

    std::stringstream out;
    out << "[";

    // Iterate through each element in the array
    for(int i = 0; i < arr.items_size(); ++i) {
        
        // Write JSON value at index
        out << JSON_val_to_str(arr.items(i).value());

        if (i < arr.items_size() - 1) {
            out << ", ";
        }

    }

    out << "]";

    return out.str();
}

std::string JSON_val_to_str(JSON_value val) {

    std::stringstream out;

    // Find the JSON value type (defined in json.proto)
    switch(val.value_case()) {
        case JSON_value::kObj:
            out << JSON_obj_to_str(val.obj());
            break;

        case JSON_value::kArr:
            out << JSON_arr_to_str(val.arr());
            break;

        case JSON_value::kNum:
            out << JSON_num_to_str(val.num());
            break;

        case JSON_value::kNull:
            out << "null";
            break;

        case JSON_value::kStr:
            out << val.str();
            break;

    }

    return out.str();
}

std::string JSON_num_to_str(JSON_number num) {

    std::stringstream out;

    // Find the number type
    switch(num.value_case()) {

        case JSON_number::kDouble:
            out << num.double_();
            break;
        
        case JSON_number::kLong:
            out << num.long_();
            break;

    }

    return out.str();
}


// Convert key-value pair to string
std::string JSON_kvpair_to_str(JSON_key_value_pair kv_pair) {

    std::stringstream out;

    out << kv_pair.key();
    out << ": ";
    out << JSON_val_to_str((kv_pair.value()));

    return out.str();
}

// Convert JSON object to string
std::string JSON_obj_to_str(JSON_object obj) {

    std::stringstream out;

    out << "{";

    // Iterate through each key-value pair in the object
    for(int i = 0; i < obj.kv_pair_size(); ++i) {

        // Serialize each key-value pair
        JSON_key_value_pair kv_pair = obj.kv_pair(i);

        out << JSON_kvpair_to_str(kv_pair);

        if (i < obj.kv_pair_size() - 1) {
            out << ", ";
        }
    } 

    out << "}";

    return out.str();
}

// Function to convert JSON inp into a string
std::string JSON_inp_to_str(JSON_inp inp) {

    // Initialize output string
    std::stringstream out;

    // Get the JSON object
    JSON_object obj = inp.obj();

    // Write serialized string
    out << JSON_obj_to_str(obj);

    JSON_key_value_pair kv_pair = inp.kv_pair();

    out << JSON_kvpair_to_str(kv_pair);

    return out.str();
}

// Function to convert JSON data into a string
std::string SerializeJSON(const JSON_opt &json_data) {

    // Initialize output string
    std::stringstream out;

    switch(json_data.value_case()) {

        case JSON_opt::kInp:
            out << JSON_inp_to_str(json_data.inp());
            break;

        case JSON_opt::kObj:
            out << JSON_obj_to_str(json_data.obj());
            break;

    }

    return out.str();

}


// Fuzzing entrypoint
extern "C" int fuzz(char *data, size_t mode_len, size_t size);

DEFINE_PROTO_FUZZER(const JSON_opt &json_data) {
    
    // Serialize JSON data into string
    std::string s = SerializeJSON(json_data);

    // Used to find the type of JSON input, functions to be called
    size_t mode_len;

    switch(json_data.value_case()) {

        // Mode length is size of object string
        case JSON_opt::kInp:
            mode_len = JSON_obj_to_str(json_data.inp().obj()).size();
            break;

        default:
            mode_len = 0;
            break;
    }

    // std::cout << "Serialized JSON: " << s << std::endl;
    fuzz((char*)s.data(), mode_len, s.size());
}
