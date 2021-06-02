#include <stdio.h>
#include <malloc.h>

int max = 0;
int vette = 0;

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

int pickNode(Node *node);

int main() {

    List *list = inizializzaList();
    push(list, 3);
    push(list, 7);
    push(list, 5);
    push(list, 8);
    push(list, 4);
    push(list, 3);
    push(list, 2);
    push(list, 9);
    push(list, 1);

    printList(list);

    printf("\nI nodi pick sono %d", pickNode(list->head));
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

int pickNode(Node *node) {

    if (node == NULL)
        return 0;

    if (node != NULL) {
        pickNode(node->next);
        if (max < node->value) {
            max = node->value;
            vette++;
        }
    }
    return vette;
}

