#include "linkedlist.h"

int main() {
    struct Node *list = createNode();
    
    for (int i = 0; i < 10; i++) {
        insertByHead(list, i + 1);
    }
    printList(list);
    insertByTail(list, 11);
    printList(list);
    insertByAppoint(list, -2, 2);
    printList(list);
    deleteByHead(list);
    printList(list);
    deleteByTail(list);
    printList(list);
    deleteByAppoint(list, 9);
    printList(list);

    return 0;
}