#include <stdio.h>


int max(int a, int b);

int zainoIterative(int w[], int p[], int n, int C);

int zainoRecursive(int w[], int p[], int n, int C);

int main() {

    int p[] = {60, 90, 120};
    int w[] = {10, 20, 30};
    int C = 50;
    int n = 4;

    printf("\nIl massimo profitto ottenuto ricorsivamente e':%d", zainoRecursive(w, p, n, C));

    printf("\nIl massimo profitto ottenuto iterativamente e':%d", zainoIterative(w, p, n, C));

    return 0;

}


int zainoIterative(int w[], int p[], int n, int C) {

    int DP[n + 1][C + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0) {
                DP[i][j] = 0;
            } else if (C < w[i - 1]) {
                DP[i][j] = DP[i - 1][j];
            } else {
                DP[i][j] = max(DP[i - 1][j], p[i - 1] + DP[i - 1][j - w[i - 1]]);
            }
        }
    }
    return DP[n][C];
}


int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int zainoRecursive(int w[], int p[], int n, int C) {

    int DP[n][C];

    if (n == 0 || C == 0) {
        return DP[n][C] = 0;
    } else if (C < w[n - 1]) {
        return DP[n][C] = zainoRecursive(w, p, n - 1, C);
    } else {
        return DP[n][C] = max(zainoRecursive(w, p, n - 1, C), p[n - 1] + zainoRecursive(w, p, n - 1, C - w[n - 1]));
    }
}