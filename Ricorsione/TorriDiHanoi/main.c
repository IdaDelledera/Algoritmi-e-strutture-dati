#include <stdio.h>

void torriDiHanoi(int n, char s, char d, char temp);


int main() {

    int n = 4;
    torriDiHanoi(n, 's', 'd', 'temp');
}


void torriDiHanoi(int n, char s, char d, char temp) {

    if (n == 1) {
        printf("\n%c -> %c", s, temp);
        return;
    }

    torriDiHanoi(n - 1, s, temp, d);
    printf("\n%c -> %c", s, temp);
    torriDiHanoi(n - 1, temp, d, s);
}

