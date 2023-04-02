#pragma once

namespace liquidCrystal {
    typedef struct liquidCrystal_t {
        private:
        int cols;
        int rows;

        public:
        void init(int columns, int rows);

    } liquidCrystal_t;

    typedef struct liquidCrystal_super_t {} liquidCrystal_super_t;
};
