#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include "core_json.h"

// Fuzzer entrypoint
extern "C" int fuzz(char *data, size_t mode_len, size_t size) {

    char* buffer;
    size_t bufferLength;
    char* queryKey;
    size_t queryKeyLength;
    char * value;
    size_t valueLength;

    // Avoid crashes on nulls
    if(size < 2 || mode_len == size) {
        return 0;
    }

    switch(mode_len) {

        // Only validate
        case 0:
            buffer = data;
            bufferLength = sizeof(buffer) - 1;
            
            JSON_Validate(buffer, bufferLength);
        
        // Validate and search
        default:
            strncpy(buffer, data, mode_len);
            bufferLength = mode_len - 1;
            data += mode_len;
            strncpy(queryKey, data, size - mode_len);
            queryKeyLength = size - mode_len - 1;
            
            JSON_Validate(buffer, bufferLength);
            JSON_Search( 
                    buffer, bufferLength, 
                    queryKey, queryKeyLength,
                    &value, &valueLength
            );
            break;            

    }
    return 0;
}
