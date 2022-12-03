#include <stdio.h>

#include "LinkedList/LinkedList.h"
#include "Data/Data.h"
#include "Node/Node.h"

int main() {
    LinkedList *list = createLinkedList();
    list->add(list, createNode(createData("Hello")));
    Node *node = createNode(createData("Maga"));
    list->add(list, node);
    list->add(list, createNode(createData("Bandera")));
    printf("%s\n", list->linkedListToString(list));

    // ???
    list->remove(list, node);

    printf("%s\n", list->linkedListToString(list));

    // FREE MEMORY
    list->listFree(list);

    /*
        LinkedListIterator it = list->getIterator();
        LinkedListIterator it = linkedListGetIterator(list);
        while (it->hasNext()) {
            it->getNext();
        }
        it->free();

        list->free();
    */

    return 0;
}