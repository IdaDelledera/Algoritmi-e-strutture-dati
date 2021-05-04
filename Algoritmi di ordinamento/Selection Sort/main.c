#include <stdio.h>

void selectionSort(int A[], int size);

void printArray(int A[], int size);

int main() {

    int A[]={22,-2,77,7,0,2,88};
    selectionSort(A, 6);

}

void selectionSort(int A[], int size){

    int i, j;

    for (i=size-1;i>0;i--){
        int max = 0;
        for (j=1;j<=i;j++){
            if(A[j]>A[max]){
                max=j;
            }
        }
        int temp=A[i];
        A[i]=A[max];
        A[max]=temp;
    }
    printArray(A, size);
}

void printArray(int A[], int size){
    for (int i=0;i<size;i++){
        printf("\n%d", A[i]);
    }
}
