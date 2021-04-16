#include <stdio.h>

int mcd(int a, int b);

int main() {

    int a=5;
    int b=5;
    printf("%d", mcd(a,b));

}

int mcd(int a, int b) {
    int app;
    if (a == b)
        return a;

     if (a < b) {
        app = mcd(a, b - a);
    }else{
         app= mcd(a-b, b);
     }

     return app;
}
