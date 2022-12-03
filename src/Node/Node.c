//
// Created by ulynaxe on 10.11.22.
//

#include <stdlib.h>

#include "Node.h"

Node* createNode(Data* data) {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;

    node->getNext = &getNext;
    node->freeNode = &freeNode;

    return node;
}

Node* getNext(Node* node) {
    return node->next;
}

void freeNode(Node* node) {
    free(node->next);
    freeData(node->data);
}
