#pragma once
#include <stdint.h>

namespace inEpFs {
    struct inEpFs_fs {
        int format(uint8_t allocationUnit_size, int quick, int performVerification);
        
        int capacity_get();
        int capacity_getFree();
        int capacity_getFree_actuall();
        
        int file_write(char* f, char* data, int fast);
        int file_delete(char* f);
        char* file_read(char* f);
        double file_size(char* f);
        double file_size_actuall(char* f);
    };
}