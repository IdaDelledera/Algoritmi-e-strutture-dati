#include <stdio.h>
#include <string.h>


int scsRecursive(char T[], char U[], int lenghtT, int lenghtU);

int scsIterative(char T[], char U[], int lenghtT, int lenghtU);

int min(int a, int b);

int main() {

    char T[] = {"AGGTAB"};
    char U[] = {"GXTXAYB"};

    int lt = strlen(T);
    int lu = strlen(U);

    printf("\nLa scsRecusive e':%d", scsRecursive(T, U, lt, lu));
    printf("\nLa scsIterative e':%d", scsIterative(T, U, lt, lu));
}


int scsRecursive(char T[], char U[], int lenghtT, int lenghtU) {

    int DP[lenghtT+1][lenghtU+1];

    if (lenghtT==0) {
        return DP[lenghtT-1][lenghtU-1] = lenghtU;
    } else if (lenghtU==0) {
        return DP[lenghtT-1][lenghtU-1] = lenghtT;
    } else if (T[lenghtT-1] == U[lenghtU-1]) {
        return DP[lenghtT-1][lenghtU-1] = 1 + scsRecursive(T, U, lenghtT - 1, lenghtU - 1);
    } else {
        return DP[lenghtT-1][lenghtU-1] = min(scsRecursive(T, U, lenghtT - 1, lenghtU),
                                              scsRecursive(T, U, lenghtT, lenghtU - 1)) + 1;
    }
}


int scsIterative(char T[], char U[], int lenghtT, int lenghtU) {

    int DP[lenghtT+1][lenghtU+1];

    for (int i = 0; i <= lenghtT; i++) {
        for (int j = 0; j <= lenghtU; j++) {
            if (i==0){
                DP[i][j] = j;
            }else if (j==0)
                DP[i][j] = i;
            else if (T[i] == U[j]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            } else {
                DP[i][j] = min(DP[i - 1][j], DP[i][j - 1]) + 1;
            }
        }
    }
    return DP[lenghtT][lenghtU];
}


int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}