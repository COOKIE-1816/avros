#pragma once
#include <stdint.h>

namespace liquidCrystal {
    typedef struct liquidCrystal_t {
        private:
        int cols;
        int rows;

        public:

        

        void init(int columns, int rows);
        void addr(uint16_t address);
        void charE(char c);
        void addChar(char c, uint16_t address);

    } liquidCrystal_t;

    typedef struct liquidCrystal_super_t {} liquidCrystal_super_t;
};
