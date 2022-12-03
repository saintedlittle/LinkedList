//
// Created by ulynaxe on 10.11.22.
//

#ifndef LINKEDLIST_DATA_H
#define LINKEDLIST_DATA_H

typedef struct Data {
    char* string;
    char* (* toString) (struct Data *data);
    void (* freeData) (struct Data* data);
} Data;

Data* createData(char* string);
void freeData(Data* data);

char* DataToString(Data *data);

#endif //LINKEDLIST_DATA_H
