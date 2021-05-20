#include <stdio.h>

void torriDiHanoi(int n, int from, int temp, int to);

void towerOfHanoi(int n, int from, int to, int temp);


int main() {

    int n = 3;
    torriDiHanoi(n, 0, 1, 2);
    printf("\nSeconda versione");
    towerOfHanoi(n, 0, 2, 1);
}


void torriDiHanoi(int n, int from, int temp, int to) {

    if (n==1){
        printf("\n%d->%d", from, to);
        return;
    }

    torriDiHanoi(n-1, from, to, temp);
    printf("\n%d->%d", from, to);
    torriDiHanoi(n-1, temp, from, to);
}

void towerOfHanoi(int n, int from, int to, int temp){

    if (n == 1){
        printf("\n%d -> %d", from, to);
        return;
    }

    towerOfHanoi(n-1, from, temp, to);
    printf("\n%d -> %d", from, to);
    towerOfHanoi(n-1, temp, to, from);
}