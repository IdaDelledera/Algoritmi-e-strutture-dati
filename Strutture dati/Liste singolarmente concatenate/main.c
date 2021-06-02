#include <stdio.h>
#include <malloc.h>

typedef struct {
    struct Node *next;
    int num;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

int isEmpty(List *list);

void push(List *list, int num);

int pop(List *list);

List *inizializzaLista();

void stampaLista(List *list);

void reverseList(List *list);

void concatList(List *list1, List *list2);

int peek(List *list);

void addInQueue(List *list, int n);

int deleteInQueue(List *list);



int main() {

    List *list1 = inizializzaLista();

    push(list1, 1);
    push(list1, 0);
    push(list1, 3);
    push(list1, 4);

    stampaLista(list1);



    pop(list1);

    stampaLista(list1);

    reverseList(list1);

    stampaLista(list1);

    List *list2 = inizializzaLista();

    push(list2, 11);
    push(list2, 3);
    push(list2, 14);
    push(list2, 1);
    addInQueue(list2, 2);

    stampaLista(list2);

    deleteInQueue(list2);

    stampaLista(list2);

    printf("La lista concatenata e':\n");
    concatList(list1, list2);

    printf("Peek list %d\n", peek(list2));


    return 0;
}


int isEmpty(List *list) {
    if (list->size == 0) {
        return 0;
    } else {
        return 1;
    }
}

void push(List *list, int newNum) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->num = newNum;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

int pop(List *list) {

    if (list->size == 1) {
        list->head = NULL;
    }

    if (isEmpty(list) == 1) {
        int removedValue = list->head->num;
        Node *removedNode = list->head;
        list->head = list->head->next;
        free(removedNode);
        list->size--;
        return removedValue;
    } else {
        printf("La lista e' vuota");
        return 0;
    }
}

List *inizializzaLista() {
    List *newList = (List *) malloc(sizeof(List));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

void stampaLista(List *list) {

    if (isEmpty(list) == 0) {
        printf("La lista e' vuota");
    }

    Node *node = list->head;

    while (node != NULL) {
        printf("%d -> ", node->num);
        node = node->next;
    }
    printf("NULL");
    puts("");
}


void reverseList(List *list) {
    Node *previous = NULL,
            *current = list->head,
            *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    list->head = previous;
}


void concatList(List *list1, List *list2) {

    if (isEmpty(list1) == 0 && isEmpty(list2) == 0)
        printf("le liste sono vuote");

    if (list1->size == 0) {
        stampaLista(list2);
        return;
    }

    if (list2->size == 0) {
        stampaLista(list1);
        return;
    }

    Node *corrente1 = list1->head;

    while (corrente1->next != NULL) {
        corrente1 = corrente1->next;
    }
    corrente1->next = list2->head;
    stampaLista(list1);
}

int peek(List *list) {
    return list->head->num;
}

void addInQueue(List *list, int n) {

    Node *current = list->head;
    Node *newNode = (Node *) malloc(sizeof(Node));

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->num = n;
    newNode->next = NULL;
    list->size++;
}

int deleteInQueue(List *list) {
    int n;
    Node *node = list->head;
    Node *lastNode = list->head;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    while (node->next != lastNode) {
        node = node->next;
    }
    node->next = NULL;
    n = lastNode->num;
    free(lastNode);
    list->size--;
    return n;
}



