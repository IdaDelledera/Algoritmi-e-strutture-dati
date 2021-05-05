#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindromeString(char a[], int i, int j);

int main() {

    char a[] = "anna";
    int i, j;
    j = strlen(a)-1;
    i = 0;

    if (palindromeString(a, i, j))
        printf("\nStringa palindroma");
    else
        printf("\nStringa non palindroma");

}


bool palindromeString(char a[], int i, int j) {

    if (strlen(a) == 1) {
        return true;
    }

    if(a[i]!=a[j])
        return false;
    else
        palindromeString(a, i+1, j-1);

    return true;
}
