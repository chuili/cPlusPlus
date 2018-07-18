#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void byteArray_to_ascii(char ascii[], char *value, int arrayLen);
void long_to_ascii(char ascii[], unsigned long value, int valueLen);

int main() {
    printf("\n--------Byte array to ASCII Conversion--------\n");
    char data[] = {0x12, 0x34, 0x56, 0x78};
    char *data_ptr = data;
    char output[8];
    byteArray_to_ascii(output, data, 4);
    // for (int i=0; i<8; i++) {
    //     printf("output[%d]: %d\n", i, output[i]);
    // }
    
    printf("\n--------Long to ASCII Conversion--------\n");
    unsigned long longInt = 151417890;
    char ascii_out[9];
    long_to_ascii(ascii_out, longInt, 9);
    return 0;
}

void byteArray_to_ascii(char ascii[], char *value, int arrayLen) {
    char *ascii_ptr = (char *)ascii;
    for (int i=0; i<arrayLen; i++) {
        printf("value[%d]: %x\n", i, value[i]);
        printf("character 1: %x\n", (value[i] & 0xF0) >> 4);
        printf("character 2: %x\n", value[i] & 0x0F);
        snprintf(ascii_ptr, 3, "%x", (value[i] & 0xF0) >> 4);
        ascii_ptr++;
        snprintf(ascii_ptr, 3, "%x", value[i] & 0x0F);
        ascii_ptr++;
    }
    for (int j=0; j<8; j++) {
       printf("ascii[%d]: %x\n", j, ascii[j]); 
    }
}

void long_to_ascii(char ascii[], unsigned long value, int valueLen) {
    char valueBytes[valueLen];
    int i;
    for (i=valueLen-1; i>=0; i--) {
        if (value != 0) {
            valueBytes[i] = value % 10;
            value /= 10;
        }
    }

    char *ascii_ptr = (char *)ascii;
    i=0;
    for (i = 0; i < valueLen; i++) {
        snprintf(ascii_ptr, 3, "%d", valueBytes[i]);
        ascii_ptr++;
        printf("ascii[%d]: %x\n", i, ascii[i]);
    }
}