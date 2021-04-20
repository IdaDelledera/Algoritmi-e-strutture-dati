#include <stdio.h>
#include <malloc.h>
#include <mem.h>


void stampaArray(int *A[]);

void push(int A[], int n);

int pop(int A[]);

int main() {

    int *dynarr = malloc(24 * sizeof(*dynarr));
    int  idx = 0;
    dynarr[idx++] = 0;
    dynarr[idx++] = 23;
    dynarr[idx++] = 34;
    dynarr[idx++] = 9;
    dynarr[idx++] = 15;

    stampaArray(dynarr);

    pop(dynarr);

    stampaArray(dynarr);
}


void push(int A[], int n){

    int *element=malloc(1*sizeof(*element));

    for (int i = 1; i < sizeof(A)+1; i++) {

    }

}

int pop(int A[]){
    int n=A[0];
    free(A[0]);
    return n;
}

void stampaArray(int *A[]){

    for (int i = 0; i < sizeof(A)+1; i++) {
        printf("\n%d", A[i]);
    }

}



