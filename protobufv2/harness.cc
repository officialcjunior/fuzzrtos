#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "core_json.h"

// Fuzzer entrypoint
extern "C" int fuzz(char *data, int mode_len, size_t size) {

    char* buffer;
    size_t bufferLength;
    char* queryKey;
    size_t queryKeyLength;
    char * value;
    size_t valueLength;
    JSONStatus_t result;

    // Avoid crashes on nulls
    if(size < 2 || mode_len >= (size + 1)) {
        return 0;
    }

    switch(mode_len) {

        // Only validate
        case 0:
            buffer = data;
            bufferLength = sizeof(buffer) - 1;
            
            JSON_Validate(buffer, bufferLength);
            break;
        
        // Validate and search
        default:

            // Hacky way to handle 2 different inputs
            buffer = (char *)malloc(mode_len);
            strncpy(buffer, data, mode_len - 1);
            bufferLength = mode_len - 1;
            data += mode_len;
            queryKey = (char *)malloc(size - mode_len);
            strncpy(queryKey, data, size - mode_len - 1);
            queryKeyLength = size - mode_len - 1;
            
            result = JSON_Validate(buffer, bufferLength);

            if(result == JSONSuccess) {
                JSON_Search( 
                        buffer, bufferLength, 
                        queryKey, queryKeyLength,
                        &value, &valueLength
                );
            }
            free(queryKey);
            free(buffer);
            break;            

    }
    return 0;
}
