#pragma once

typedef struct basic_outputStruct_t {
    int status;
    int code;

    char* output;
} basic_outputStruct_t;

char** basic_script;

basic_outputStruct_t basic(char* BASIC);
void basic_createScriptLine(char* scriptLine);
