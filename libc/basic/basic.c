#include "basic.h"

int INTEGER(char* CHAR_ARRAY) {
     int num = 0;
     int n = sizeof(CHAR_ARRAY) / sizeof(CHAR_ARRAY[0]);

     for(int i = 0; i < n; i++) {
        num = num * 10 + (int(CHAR_ARRAY[i]) - 48);
     }

     return num;
};

char* getFirstWord(char* STRING, char separator) {
    char* buff;
    int n = sizeof(STRING) / sizeof(STRING[0]);

    for(int i = 0; i < n; i++) {
        if(STRING[i] == separator) {
            break;
        }

        char buff[i] = STRING[i];
    }

    return buff;
}

//char* memory;
//basic_link_t memory_map[512]; uint32_t memory_map_nextBit = 1;

typedef struct basic_outputStruct_t {
    int status;
    int code;

    char* output;
} basic_outputStruct_t;

/*typedef struct basic_link_t {
    char* name;
    uint32_t type;

    uint16_t address_start;
    uint16_t address_end;
}


void basic_createScriptLine(char* scriptLine) {
    int line = INTEGER(getFirstWord(scriptLine, ' '));
    int n = sizeof(getFirstWord(scriptLine, ' ')) / sizeof(getFirstWord(scriptLine, ' '));

    for(int i = 0; i < n; i++) {
        scriptLine[i] = scriptLine[i + 1];
    }


    basic_script[line] = scriptLine;
}*/










/*basic_outputStruct_t basic_LET(uint32_t type, char* name, uint16_t address_start) {
    basic_outputStruct_t out;
    if(type < 0x00 || type > 0x03) {
        out.status = 0xFF;
        out.code = 0x00000001;
        out.output = "Unknown (or unsupported) data type.";

        return out;
    }

    if(memory_map_nextBit > 512) {
        out.status = OxFF;
        out.code = 0x00000002;
        out.output = "Too much variables! (> 512)";

        return out;
    }


}*/

basic_outputStruct_t basic(char* BASIC) {
    char* numbers = "0123456789";

    for(int i = 0; i < 10; i++) {
        if(BASIC[0] == numbers[i]) {
            // Starts with number -> Declare as script line
            //basic_createScriptLine(BASIC);
        }
    }
}
