#include <stdio.h>
#include <string.h>

int lcsRecursive(char *T, char *U, int lenghtT, int lenghtU);

int max(int c1, int c2);

int lcsIterative(char T[], char U[], int lenghtT, int lenghtU);

int main() {

    char T[] = "ATTCGATTTTT";
    char U[] = "AGTTTDDETTT";

    int lunghezzaT = strlen(T);
    int lunghezzaU = strlen(U);

    printf("\nIl risultato della LCS ricorsiva e':%d", lcsRecursive(T, U, lunghezzaT, lunghezzaU));
    printf("\nIl risultato della LCS iterativa e':%d", lcsIterative(T, U, lunghezzaT, lunghezzaU));
}

int max(int c1, int c2) {
    if (c1 > c2)
        return c1;
    else
        return c2;
}


int lcsRecursive(char T[], char U[], int lenghtT, int lenghtU) {
    int DP[lenghtT][lenghtU];

    if (lenghtT == 0 || lenghtU == 0)
        return 0;

    if (T[lenghtT - 1] == U[lenghtU -
                            1]) { //sottraggo -1 dalle lunghezze delle sctringhe perchè lavoriamo sempre con array. Gli array partono da 0 con la numerazione degli indici
        DP[lenghtT - 1][lenghtU - 1] = 1 + lcsRecursive(T, U, lenghtT - 1, lenghtU - 1);
        return DP[lenghtT - 1][lenghtU - 1];
    } else {
        DP[lenghtT - 1][lenghtU - 1] = max(lcsRecursive(T, U, lenghtT - 1, lenghtU),
                                           lcsRecursive(T, U, lenghtT, lenghtU - 1));
    }
    return DP[lenghtT - 1][lenghtU - 1];
}

int lcsIterative(char T[], char U[], int lenghtT, int lenghtU) {
    int DP[lenghtT+1][lenghtU+1];
    int i, j;

    for (i = 0; i <= lenghtT; i++) {
        for (j = 0; j <= lenghtU; j++) {  //maggiore uguale sempre perchè la numerazione della matrice parte da 0 e arriva alla lunghezza rispettiva 
            if (i == 0 || j == 0) {
                DP[i][j] = 0;
            } else if (T[i] == U[j]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
    return DP[lenghtT][lenghtU];
}






