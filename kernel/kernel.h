#pragma once
#include <stdint.h>

namespace kernel {
    /*int kmodule_load(int module_);
    int kmodule_unload(int module_);
    int drvload(int drv);*/

    class Sleep {
        private:
        uint8_t* wakeEventList;
        uint8_t* wakeEventList_requiredValues;
        int wakeEventList_length;

        public:
        void addWakeEvent(uint8_t func, uint8_t requiredValue);
        void removeWakeEvent(uint8_t func);
        //void forceWakeUp();
        void sleep();

    };
};