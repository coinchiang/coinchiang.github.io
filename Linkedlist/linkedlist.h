#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(void);

void insertByHead(struct Node *headNode, int data);

void insertByTail(struct Node *headNode, int data);

void insertByAppoint(struct Node *headNode, int data, int value);

void deleteByHead(struct Node *headNode);

void deleteByTail(struct Node *headNode);

void deleteByAppoint(struct Node *headNode, int value);

void printList(struct Node *headNode);

#endif