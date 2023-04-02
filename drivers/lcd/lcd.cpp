#include "lcd.h"

typedef struct liquidCrystal::liquidCrystal_t {
    public:
        int cols;
        int rows;
    void init(int columns, int rows) {
        this->cols = columns;
        this->rows = rows;
    }
} liquidCrystal_t;