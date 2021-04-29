#include <stdio.h>
#include <malloc.h>

#define dimensione 7

typedef enum {
    false, true
} boolean;


typedef struct {
    int *heap;
    int size;
} Heap;

int heapFull(Heap *heap);

int isEmpty(Heap *heap);

void insert(Heap *heap, int val);

int getParent(int indexCurrent);

void heapify(Heap *heap, int indexNew);

void printHeap(Heap *heap);

int getChild(int index, boolean isLeft);

void controlloInferiore(Heap *heap, int lastIndex, int index);

void deleteElement(Heap *heap, int index);

void heapSort(Heap *heap);

int peek(Heap *heap);

int main() {

    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->heap = (int *) malloc(sizeof(int) * (10));

    int size = 7;

    for (int i = 0; i < size; i++) {
        heap->heap[i] = 0;
    }
    heap->size = 0;


    insert(heap, 77);
    insert(heap, 66);
    insert(heap, 57);
    insert(heap, 55);
    insert(heap, 7);

    printf("\nHeap\n");
    printHeap(heap);

  // deleteElement(7, 4);
   //printHeap(heap);


    printf("Radice heap: %d", peek(heap));

    //heapSort(heap);
   // printHeap(heap);

}

int heapFull(Heap *heap) {
    if (heap->size == dimensione)
        return 1;
    else
        return 0;
}

int isEmpty(Heap *heap) {
    if (heap->size == 0)
        return 1;
    else
        return 0;
}

void insert(Heap *heap, int val) {

    if (heapFull(heap) == 1)
        perror("Heap pieno!");

    heap->heap[heap->size++] = val;

    heapify(heap, heap->size - 1);
}

void heapify(Heap *heap, int indexNew) {

    int newValue = heap->heap[indexNew];

    while (indexNew > 0 && newValue > heap->heap[getParent(indexNew)]) {
        heap->heap[indexNew] = heap->heap[getParent(indexNew)];
        indexNew = getParent(indexNew);
    }
    heap->heap[indexNew] = newValue;
}

int getParent(int indexCurrent) {
    return ((indexCurrent - 1) / 2);
}


int getChild(int index, boolean isLeft) {
    return isLeft == true ?
           (2 * index) + 1 : (2 * index) + 2;
}

void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d, ", heap->heap[i]);
    }
}

void controlloInferiore(Heap *heap, int index, int lastIndex) {

    int childToSwap;

    while (index<=lastIndex){
        int leftChildIndex = getChild(index, true);
        int rightChildIndex = getChild(index, false);

        if (leftChildIndex<=lastIndex){
            if (rightChildIndex>lastIndex){
                childToSwap = leftChildIndex;
            } else{
                childToSwap = heap->heap[leftChildIndex] > heap->heap[rightChildIndex] ? leftChildIndex : rightChildIndex;
            }

            if (heap->heap[childToSwap] > heap->heap[index]){
                int temp = heap->heap[childToSwap];
                heap->heap[childToSwap] = heap->heap[index];
                heap->heap[index] = temp;
            } else{
                break;
            }
            index = childToSwap;
        } else{
            break;
        }
    }
}

void deleteElement(Heap *heap, int index){

        if (isEmpty(heap) == true) {
            perror("Heap vuoto");
        }

        heap->heap[index] = heap->heap[heap->size - 1];
        heap->size--;

        if (index == 0 || heap->heap[index] < heap->heap[getParent(index)]) {
            controlloInferiore(heap, index, heap->size-1);
        } else{
            heapify(heap, index);
        }
}

int peek(Heap *heap){
    return heap->heap[0];
}

void heapSort(Heap *heap){

    int lastIndex=heap->size-1;

    while(lastIndex>0){
        int temp = heap->heap[0];
        heap->heap[0] = heap->heap[lastIndex];
        heap->heap[lastIndex] = temp;
    }
    controlloInferiore(heap, 0, lastIndex);
}

