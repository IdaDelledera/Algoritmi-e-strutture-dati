#include <stdio.h>

void torriDiHanoi(int n, char A, char C, char B);


int main() {

    int n = 4;
    torriDiHanoi(n, 'A', 'C', 'B');
}


void torriDiHanoi(int n, char A, char C, char B) {

    if (n == 1) {
        printf("\n%c -> %c", A, C);
        return;
    }

    torriDiHanoi(n - 1, A, B, C);
    printf("\n%c -> %c", A, C);
    torriDiHanoi(n - 1, B, C, A);

}

