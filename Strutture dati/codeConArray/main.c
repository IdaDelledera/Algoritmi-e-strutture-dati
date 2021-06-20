#include <stdio.h>
#include <stdlib.h>

#define Q_LEN 10 // Lunghezza della coda

int queue[Q_LEN]; // array coda

int index=0;

void enqueue(int element);

int dequeue();

void printQueue();




int main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printQueue();
    puts("");

    dequeue();
    printQueue();
    puts("");


}

void enqueue(int element) {
    if (index == Q_LEN)
        printf("Coda piena !\n");
    else {
        queue[index] = element;
        index=index+1;
    }
}

int dequeue() {
    if (index == 0)
        printf("Coda vuota !\n");
    else
        index=index-1;
    return queue[index];
}

void printQueue(){
    for(int i=0;i<index;i++)
        printf("%d\n",queue[i]);
}
