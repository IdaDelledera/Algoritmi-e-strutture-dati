#include <stdio.h>
#include <malloc.h>

typedef struct {
    struct Node *next;
    int value
} Node;

typedef struct {
    Node *head;
    int size;
} List;

void push(List *list, int num);

List *inizializzaList();

void printList(List *list);

int pickNode(List *list, Node *current);

int main() {

    List *list = inizializzaList();
    push(list, 22);
    push(list, 55);
    push(list, 6);
    push(list, 1);
    push(list, 0);

    printList(list);

    printf("\nI nodi pick sono %d", pickNode(list, list->head));
}

List *inizializzaList() {
    List *list = (List *) malloc(sizeof(list));
    list->head = NULL;
    list->size = 0;
    return list;
}

void push(List *list, int num) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = num;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void printList(List *list) {

    Node *current = list->head;
    while (current != NULL) {
        printf("%d->", current->value);
        current = current->next;
    }
    printf("NULL");
}

int pickNode(List *list, Node *current) {

    int app;
    current = list->head;
    Node *next = current->next;

    app = list->size;

    if (list->size == 0)
        return 0;

    if (list->size == 1)
        return 1;

    if (current->value < next->value) {
        app--;

    }

    printf("\n%d", app);

    return app;
}

