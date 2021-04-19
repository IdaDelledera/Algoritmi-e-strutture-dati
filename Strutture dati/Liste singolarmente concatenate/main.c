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

int main() {

    List *newList = inizializzaLista();

    push(newList, 1);
    push(newList, 2);
    push(newList, 3);
    push(newList, 4);

    stampaLista(newList);

    pop(newList);

    stampaLista(newList);


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

void stampaLista(List *list){

    if (isEmpty(list)==0){
        printf("La lista e' vuota");
    }

    Node *node = list->head;

    while (node!=NULL){
        printf("%d -> ", node->num);
        node = node->next;
    }
    printf("NULL");
    puts("");
}