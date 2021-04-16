#include <stdio.h>

#define max 6

void riempiArray();

void stampaArray();

int partizionamentoPivotIniziale();

void quickSortIn();

void quicksortMe(int A[], int primo, int ultimo);

int main() {

    int A[max];
    int scelta;

    printf("\n******************SCELTA********************\n");
    printf("\n1. Quick sort con pivot in prima posizione");
    printf("\n2. Quick sort con pivot centrale");
    printf("\nScelta: ");
    scanf("%d", &scelta);

    while (scelta != 3) {
        switch (scelta) {
            case 1:
                riempiArray(A, max);
                printf("\nL'array inserito e':\n");
                stampaArray(A, max);

                quickSortIn(A, 0, 6);
                printf("\nL'array ordinato e':\n");
                stampaArray(A, max);
                break;
            case 2:
                riempiArray(A, max);
                printf("\nL'array inserito e':\n");
                stampaArray(A, max);

                quicksortMe(A, 0, 6);
                printf("\nL'array ordinato e':\n");
                stampaArray(A, max);
                break;
            case 3:
                break;
        }
    }
    return 0;
}


void riempiArray(int A[], int size) {

    for (int i = 0; i < size; i++) {
        printf("\nInserisci elemento %d all'interno dell'array: ", i);
        scanf("%d", &A[i]);
    }
}

void stampaArray(int A[], int size) {

    for (int i = 0; i < size; i++) {
        printf("%d\n", A[i]);
    }
}

void quickSortIn(int A[], int primo, int ultimo) {

    if (ultimo - primo < 2)
        return;

    int indicePivot = partizionamentoPivotIniziale(A, primo, ultimo);
    quickSortIn(A, primo, indicePivot);
    quickSortIn(A, indicePivot + 1, ultimo);

}

int partizionamentoPivotIniziale(int A[], int primo, int ultimo) {

    int pivot = A[primo];
    int i = primo;
    int j = ultimo;

    while (i < j) {

        while (i < j && A[--j] >= pivot);
        if (i < j) {
            A[i] = A[j];
        }

        while (i < j && A[++i] <= pivot);
        if (j < i) {
            A[j] = A[i];
        }

    }
    A[j] = pivot;
    return j;
}

void quicksortMe(int A[], int primo, int ultimo){

    if(primo>=ultimo)
        return;

    int pivot = A[(primo+ultimo)/2];
    int i = primo;
    int j = ultimo;

    while (i <= j) {
        while (A[j] > pivot)
            j--;
        while (A[i] < pivot)
            i++;

        if (i <= j) {
            if (i == j) return;

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }
    if (j > primo)
        quicksortMe(A, primo, j);
    if (i < ultimo)
        quicksortMe(A, i, ultimo);
}