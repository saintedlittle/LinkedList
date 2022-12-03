//
// Created by ulynaxe on 05.11.22.
//

#include <stdbool.h>
#include <stdlib.h>

#include "../Node/Node.h"

#ifndef LINKEDLIST_LINKEDLIST_H

#define LINKEDLIST_LINKEDLIST_H

typedef struct LinkedList {
    struct Node *head;
//    struct LinkedList* (* createList) ();
    struct LinkedList* (* add) (struct LinkedList* list, Node *node);
    struct LinkedList* (* remove) (struct LinkedList* list, Node *node);
    void (* listFree) (struct LinkedList* list);
    Node* (* getLast) (struct LinkedList* list);
    bool (*isEmpty) (struct LinkedList* list);
    Node* (* getHead) (struct LinkedList* list);
    char* (* linkedListToString) (struct LinkedList* list);
} LinkedList;

Node* getHead(LinkedList *list);

bool isEmpty(LinkedList *list);

Node* getLast(LinkedList *list);

int LinkedListSize(LinkedList *list);

LinkedList* linkedListAdd(LinkedList *list, Node *node);

void linkedListFree(LinkedList *list);

LinkedList* linkedListRemove(LinkedList *list, Node *node);

char* linkedListToString(LinkedList *list);

LinkedList* createLinkedList();

#endif //LINKEDLIST_LINKEDLIST_H
