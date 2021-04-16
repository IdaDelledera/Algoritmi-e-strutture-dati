#include <stdio.h>

int nFibRecursive(int n);

int nFibIterative(int n);

int main() {

    int n = 6;

    printf("\nn-esimo n di Fibonacci calcolato ricorsivamente e':%d", nFibRecursive(n));
    printf("\nn-esimo n di Fibonacci calcolato iterativamente e':%d", nFibIterative(n));

}

int nFibRecursive(int n) {

    int DP[n + 1];

    if (n <= 1)
        return n;
    else
        return DP[n] = nFibRecursive(n - 1) + nFibRecursive(n - 2);
}

int nFibIterative(int n) {

    int DP[n + 1];
    int i;

    DP[0]=0;
    DP[1]=1;

    for (i = 2; i <= n; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    return DP[n];
}


