#include <stdio.h>
#include <malloc.h>


typedef struct Node {
    struct Node *next;
    int num;
} Node;

typedef struct {
    struct Node *head;
    int size;
} List;

List *inizializzaList();

void push(List *list, int n);

void printList(List *list);

void mergeList(List *list1, List *list2);

void bubbleSort(int A[], int size);

void copyInList(int A[], int size);

int main() {

    List *list1 = inizializzaList();

    push(list1, 1);
    push(list1, 3);
    push(list1, 5);
    push(list1, 8);
    printList(list1);

    List *list2 = inizializzaList();

    push(list2, 66);
    push(list2, 55);
    push(list2, 90);
    push(list2, 8);
    printList(list2);

    mergeList(list1, list2);

    return 0;
}


void push(List *list, int n) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->num = n;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

List *inizializzaList() {
    List *newList = (List *) malloc(sizeof(List));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

void printList(List *list) {

    Node *node = list->head;

    while (node != NULL) {
        printf("%d -> ", node->num);
        node = node->next;
    }
    printf("NULL");
    puts("");
}

void mergeList(List *list1, List *list2){
    Node *node1 = list1->head;
    Node *node2=list2->head;
    int n = list1->size+list2->size;
    int A[n];
    int i=0;

    while (node1!=NULL){
       A[i]=node1->num;
       i++;
       node1=node1->next;
       while (node2!=NULL){
           A[i]=node2->num;
           i++;
           node2=node2->next;
       }
    }

    bubbleSort(A, n);
    copyInList(A,n);
}

void bubbleSort(int A[], int size){

    int app;

    for (int i=size-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(A[j]>A[j+1]){
                app=A[j];
                A[j]=A[j+1];
                A[j+1]=app;
            }
        }
    }
}


void copyInList(int A[], int size){

    List *newList = inizializzaList();

    for (int i=size-1;i>=0;i--){
      push(newList, A[i]);
    }
    printList(newList);
}

