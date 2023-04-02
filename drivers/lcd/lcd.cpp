#include "lcd.h"

typedef struct liquidCrystal::liquidCrystal_t {
    private:
    int cols;
    int rows;

    public:
    void init(int columns, int rows) {
        this->cols = columns;
        this->rows = rows;
    }
} liquidCrystal_t;