//
// Created by ulynaxe on 10.11.22.
//

#include <stdlib.h>
#include <string.h>
#include "Data.h"

Data* createData(char* string) {
    Data *data = malloc(sizeof(Data));
    data->string = string;

    data->toString = &DataToString;
    data->freeData = &freeData;
    return data;
}

void freeData(Data* data) {
    free(data->string);
}

char* DataToString(Data *data) {
    char* result = malloc(sizeof(data->string));
    strcpy(result, data->string);

    return result;
}