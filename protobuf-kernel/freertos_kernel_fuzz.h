#include "json.pb.h"
#include <bits/stdc++.h>
#include <string>

std::string JSON_arr_to_str(JSON_array arr);
std::string JSON_val_to_str(JSON_value val);
std::string JSON_num_to_str(JSON_number num);
std::string JSON_kvpair_to_str(JSON_key_value_pair kv_pair);
std::string JSON_obj_to_str(JSON_object obj);
std::string JSON_inp_to_str(JSON_inp inp);
std::string SerializeJSON(const JSON_inp &json_data);
