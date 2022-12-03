//
// Created by ulynaxe on 05.11.22.
//

#include "LinkedList.h"
#include "../Util/Util.h"

#include <stdlib.h>
#include <string.h>

Node* getHead(LinkedList *list) {
    return list->head;
}

bool isEmpty(LinkedList *list) {
     Node *head = getHead(list);
    if (head->next != NULL) {
        return false;
    }
    return true;
}

Node* getLast(LinkedList* list) {
    Node *hp = list->head;
    if (isEmpty(list)) {
        return list->head;
    }

    Node *tmp = hp->next;
    while (tmp->next) {
        tmp = getNext(tmp);
    }

    return tmp;
}

int LinkedListSize(LinkedList *list) {
    int result = 1;
    Node *node = malloc(sizeof(Node));
    if (isEmpty(list)) {
        return result;
    }
    node->next = list->head->next;
    while(node->next != NULL) {
        result++;
        node = node->next;
    }
    return result;
}

LinkedList* linkedListAdd(LinkedList *list, Node* node) {
    getLast(list)->next = node;
    return list;
}

LinkedList* linkedListRemove(LinkedList* list, Node* node) {
    if (isEmpty(list)) {
        return list;
    }
    Node *tmp = list->head->next;
    while (tmp->next) {
        if (tmp->next == node) {
            tmp->next = node->next;
            return list;
        }
        tmp = getNext(tmp);
    }
    freeNode(node);
}

void linkedListFree(LinkedList *list) {
    Node *tmp = list->head;
    Node *next;
    while (tmp->next) {
        next->next = getNext(tmp->next);
        freeNode(tmp);
        tmp->next = next->next;
    }

    free(list);
}

char* linkedListToString(LinkedList *list) {

    if (isEmpty(list))
        return "";

    Node *head = getHead(list);

    size_t size = sizeof(&head);
    char* result = malloc(size);

    if (head->data->string != NULL) strcpy(result, head->data->string);
    else result = "";

    while ((head = getNext(head))->next != NULL) {
        result = concat(result, head->data->string, "\n");
    }

    result[strlen(result) - 1] = '\0';

    return result;
}

LinkedList* createLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = malloc(sizeof(Node));
    list->head->next = NULL;
    list->head->data = malloc(sizeof(Data));

    list->add = &linkedListAdd;
    list->remove = &linkedListRemove;
    list->getHead = &getHead;
    list->getLast = &getLast;
    list->isEmpty = &isEmpty;
    list->listFree = &linkedListFree;
    list->linkedListToString = &linkedListToString;

    return list;
}