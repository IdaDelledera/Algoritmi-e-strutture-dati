#include <stdio.h>


void riempiArray();

void bubbleSort();

void stampaArray();

int main() {

    int size = 5;
    int A[size];

    riempiArray(A, size);
    printf("\nL'array inserito e':");
    stampaArray(A,size);

    bubbleSort(A,size);
    printf("\nL'array rioridinato e':");
    stampaArray(A,size);

}


void riempiArray(int A[], int size) {

    for (int i = 0; i < size; i++) {
        printf("\nInserisci l'elemento %d all'interno dell'array:", i);
        scanf("%d", &A[i]);
    }

}


void stampaArray(int A[], int size){

    for (int i = 0; i < size; i++) {
        printf("\n%d", A[i]);
    }
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


