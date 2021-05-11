#ifndef QUEUE_LIBRARY_H
#define QUEUE_LIBRARY_H

#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
} *head = NULL, *tail = NULL;

typedef struct Node Node;

int isEmpty() {
    return head == NULL;
}

void enqueue(int value) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty()) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}


int dequeue() {

    if (isEmpty()) {
        printf("Lista vuota");
        return 0;
    }

    Node *removedNode = head;
    int removedValue = head->value;

    if (head = tail) {
        head = NULL;
        tail = NULL;
        free(removedNode);
        return removedValue;
    }

    head = head->next;
    free(removedNode);
    return removedValue;
}


#endif //QUEUE_LIBRARY_H
