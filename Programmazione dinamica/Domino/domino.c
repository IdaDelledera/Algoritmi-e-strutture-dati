#include <stdio.h>

#define num 4

int dominoRecursive(int n);

int dominoIterative(int n);

int main() {


    printf("\nLe possibili disposizioni calcolare ricorsivamente in base al numero di tessere sono:%d",
           dominoRecursive(num));
    printf("\nLe possibili disposizioni calcolare iterativamente in base al numero di tessere sono:%i",
           dominoIterative(num));
    return 0;
}


int dominoRecursive(int n) {
    int DP[n];

    if (n == 0 || n == 1)
        return 1;
    else if (n > 1) {
        DP[n] = dominoRecursive(n - 1) + dominoRecursive(n - 2);
    }
    return DP[n];
}

int dominoIterative(int n) {
    int DP[n];
    int i;

    DP[0] = 1;
    DP[1] = 1;

    for (i = 2; i <= n; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    return DP[n];
}
