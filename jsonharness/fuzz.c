#include "stdint.h"
#include "stdbool.h"
#include <stdio.h>
#include "core_json.h"

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	JSONStatus_t result;
	char data1[size - 10];
	char data2[10];
	char * value;
    size_t valueLength;

	switch(data[0] % 2) {

		// Validate and search
		case 0: {
			if(size <= 10) {
				goto VALIDATE;
			}
			memcpy(data1, data, size - 10);
			memcpy(data2, data + size - 10, 10);

			result = JSON_Validate(data, size);

			if(result == JSONSuccess) {

				JSON_Search(data1, size - 10, data2, 10, &value, &valueLength );
			}

			break;
		}

		// Only validate
		case 1: {
			VALIDATE:
				JSON_Validate(data, size);			
				break;
		}

	}

	return 0;
}
