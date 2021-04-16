#include <stdio.h>

void riempiArray();

void stampaArray();

void insertionSort();

int main() {

    int size=5;
    int A[size];

    riempiArray(A, size);
    printf("\nL'array inserito e':");
    stampaArray(A, size);

    insertionSort(A, size);
    printf("\nL'array ordinato e':");
    stampaArray(A, size);

}


void riempiArray(int A[], int size){

    for(int i=0;i<size;i++){
        printf("\nInserisci elemento %d all'interno dell'array: ", i);
        scanf("%d", &A[i]);
    }
}

void stampaArray(int A[], int size){
    for(int i=0;i<size;i++){
        printf("\n%d", A[i]);
    }
}

void insertionSort(int A[], int size){
    int app;
    for(int i=1;i<size;i++){
        for(int j=i;j>0;j--){
            if(A[j]<A[j-1]){
                app=A[j];
                A[j]=A[j-1];
                A[j-1]=app;
            }
        }
    }
}