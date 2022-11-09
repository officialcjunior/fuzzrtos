#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include "json_writer.h"
#include "json.pb.h"
#include "core_json.pb.h"
#include "src/libfuzzer/libfuzzer_macro.h"
#include "skip_assert.h"
#include "json_writer.h"

using namespace std;

extern "C"{
    #include "core_json.h"
}

void fuzz_core_json( char *buffer, char *queryKey);

DEFINE_PROTO_FUZZER( const core_json_pair& input_pair) {
    string buffer = JSON_value_to_string(input_pair.buffer());
    string query = JSON_value_to_string(input_pair.buffer());
    
    char *char_buffer = new char[buffer.size()+1];
    char *char_query = new char[query.size()+1];
    
    memcpy(char_buffer,buffer.c_str(),buffer.size());
    memcpy(char_query,query.c_str(),query.size());

    char_buffer[buffer.size()]=0;
    char_query[query.size()]=0;

    fuzz_core_json(char_buffer, char_query);
}

void fuzz_core_json( char *buffer, char *query){
    char *value;
    size_t bufferLength = sizeof( buffer ) - 1;
    size_t queryKeyLength = sizeof( query ) - 1;
    size_t valueLength;
    JSONStatus_t result;
    
    cout << "buffer:" << buffer << endl;
    cout << "queryKey:" << query << endl;

    jmp_buf *env = get_jmp_buf();
    if (setjmp(*env)) {
        cout << "hit assert on input, skipping" << endl;
        return;
    }

    result = JSON_Validate( buffer, bufferLength);
    if( result == JSONSuccess )
    {
        result = JSON_Search( buffer, bufferLength, query, queryKeyLength, &value, &valueLength );
    }
    
    if( result == JSONSuccess )
    {
        char save = value[ valueLength ];
        value[ valueLength ] = '\0';
        cout << "Found: "<< query << "-> " << value << "%s" << endl;
        value[ valueLength ] = save;
    }
}