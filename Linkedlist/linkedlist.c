#include "linkedlist.h"

//创建节点
struct Node *createNode(void) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->next = NULL;

    return newNode;
}
//表头插入
void insertByHead(struct Node *headNode, int data) {
    struct Node *newNode = createNode();

    newNode->data = data;
    newNode->next = headNode->next;
    headNode->next = newNode;
}
//表尾插入
void insertByTail(struct Node *headNode, int data) {
    struct Node *newNode = createNode();

    while (headNode->next != NULL) {
        headNode = headNode->next;
    }

    newNode->data = data;
    newNode->next = headNode->next;
    headNode->next = newNode;
}
//指定位置前插入
void insertByAppoint(struct Node *headNode, int data, int value) {
    struct Node *newNode = createNode();
    struct Node *valueNode, *valueFrontNode;

    newNode->data = data;
    valueFrontNode = headNode;
    valueNode = valueFrontNode->next;

    while (valueNode != NULL && valueNode->data != value) {
        valueFrontNode = valueNode;
        valueNode = valueFrontNode->next;
    }

    if (valueNode == NULL) {
        printf("value is not in the list\n");
    } else {
        valueFrontNode->next = newNode;
        newNode->next = valueNode;
    }
}
//从表头删除
void deleteByHead(struct Node *headNode) {
    if (headNode->next != NULL) {
        struct Node *firstNode = headNode->next;
        headNode->next = firstNode->next;
        free(firstNode);
    } else {
        printf("Nothing left at all\n");
    }
}
//从表尾删除
void deleteByTail(struct Node *headNode) {
    if (headNode->next != NULL) {
        struct Node *newLastNode = headNode;
        struct Node *lastNode = newLastNode->next;

        while (lastNode->next != NULL) {
            newLastNode = lastNode;
            lastNode = newLastNode->next;
        }

        free(lastNode);
        newLastNode->next = NULL;
    } else {
        printf("Nothing left at all\n");
    }
}
//从指定位置删除
void deleteByAppoint(struct Node *headNode, int value) {
    if (headNode->next != NULL) {
        struct Node *deleteNode, *deleteFrontNode;

        deleteFrontNode = headNode;
        deleteNode = deleteFrontNode->next;

        while (deleteNode != NULL && deleteNode->data != value) {
            deleteFrontNode = deleteNode;
            deleteNode = deleteFrontNode->next;
        }
        if (deleteNode == NULL) {
            printf("value is not in the list\n");
        } else {
            deleteFrontNode->next = deleteNode->next;
            free(deleteNode);
        }
    } else {
        printf("Nothing left at all\n");
    }
}
//打印链表
void printList(struct Node *headNode) {
    headNode = headNode->next;

    while (headNode->next != NULL) {
        printf("%d -> ", headNode->data);
        headNode = headNode->next;
    }
    
    printf("%d\n", headNode->data);
}