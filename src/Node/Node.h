//
// Created by ulynaxe on 10.11.22.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include "../Data/Data.h"

typedef struct Node {
    struct Node *next;
    struct Data *data;
//    struct Node* (* createNode) (Data *Data);
    struct Node* (* getNext) (struct Node* node);
    void (* freeNode) (struct Node* node);
} Node;

Node* createNode(Data *data);
Node* getNext(Node *node);

void freeNode(Node* node);

#endif //LINKEDLIST_NODE_H
