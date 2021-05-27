#include <stdio.h>
#include <math.h>

int add(int A[], int i, int j);

void riempiArray(int A[], int size);

void stampaArray(int A[], int size);


int main() {

    int A[4];
    riempiArray(A, 4);
    stampaArray(A, 4);

    printf("\nLa somma e':");
    printf("%d\n",add(A, 0, 3));

    printf("\n%d", add(A, 0, 4));

}

int add(int A[], int i, int j){

    int app = (i+j)/2;
    if(i>j)
        return 0;
    if(i==j){
        return A[i];
    }else{
        int m = floor(app);
        return (add(A,i,m)+add(A,m+1,j));
    }
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