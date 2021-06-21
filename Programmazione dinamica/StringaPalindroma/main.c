#include <stdio.h>
#include <string.h>


int min(int a, int b);

int minPal(char s[], int n);

int minPalRecursive(char s[], int i, int j);


int main() {

    char s[] = "";
    int n = strlen(s) - 1;

    printf("FUNZIONE RICORSIVA");
    printf("\nIl minimo numero di caratteri da aggiungere alla stringa per renderla palindroma e':%d",
           minPalRecursive(s, 0, n));
    puts("");

    printf("FUNZIONE ITERATIVA");
    printf("\nIl minimo numero di caratteri da aggiungere alla stringa per renderla palindroma e':%d", minPal(s, n));
    puts("");

}

int minPal(char s[], int n) {

    int DP[n + 1][n + 1];
    int i, j;

    for (i = 0; i <= n; ++i) {
        for (j = n; j >= 0; j--) {
            DP[i][j]=1;
        }
    }

    for (i = 0; i <= n; ++i) {
        for (j = n; j >= 0; j--) {
            if (j <= i) {
                DP[i][j] = 0;
                printf("\n%d", DP[i][j]);
            } else if (s[i] == s[j] && i<j) {
                DP[i][j] = DP[i + 1][j - 1];
                printf("\n%d", DP[i][j]);
            } else if (s[i] != s[j]) {
                DP[i][j] = min(DP[i + 1][j], DP[i][j - 1])+1;
                //printf("\n%d min", min(DP[i + 1][j], DP[i][j - 1])+1);
                printf("\n%d", DP[i][j]);
            }
        }
    }
    return DP[0][n];
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int minPalRecursive(char s[], int i, int j) {

    int DP[j][j];

    if (j <= i) {
        DP[i][j] = 0;
        printf("\n%d", DP[i][j]);
    } else if (s[i] == s[j]) {
        DP[i][j] = minPalRecursive(s, i + 1, j - 1);
        printf("\n%d", DP[i][j]);
    } else {
        DP[i][j] = min(minPalRecursive(s, i + 1, j), minPalRecursive(s, i, j - 1)) + 1;
        printf("\n%d", DP[i][j]);
    }
    return DP[i][j];
}

