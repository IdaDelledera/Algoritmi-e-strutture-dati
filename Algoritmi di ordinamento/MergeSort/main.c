#include <stdio.h>

#define max 5

void merge(int a[], int primo, int medio, int ultimo);

void stampaArray(int A[], int size);

void riempiArray(int A[], int size);

void mergeSort(int a[], int primo, int ultimo);

int main() {
    int  V[max];
    riempiArray(V,5);
    mergeSort(V, 0, 5-1);
    stampaArray(V, 5);
    return(0);
}


void merge(int a[], int primo, int medio, int ultimo){
    int i, j, k=0, b[max];
    i = primo;
    j = medio + 1;

    while (i <= medio && j <= ultimo) {
        if (a[i]<a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= medio) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= ultimo) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (k=primo; k <= ultimo; k++)
        a[k] = b[k - primo];
    return;
}

void mergeSort(int a[], int primo, int ultimo) {
    int q;
    if (primo < ultimo) {
        q = (primo + ultimo) / 2;
        mergeSort(a, primo, q);
        mergeSort(a, q+1, ultimo);
        merge(a, primo, q, ultimo);
    }
    return;
}

void stampaArray(int A[], int size){
    for(int i=0;i<size;i++){
        printf("%d\n", A[i]);
    }
}

void riempiArray(int A[], int size){
    for (int i=0;i<size;i++){
        printf("Inserisci elemento all'interno dell'array:\n");
        scanf("%d", &A[i]);
    }
}



