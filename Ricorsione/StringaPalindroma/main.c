#include <stdio.h>
#include <string.h>
#include <stdbool.h>

    bool palindromeString(char w[]);

    int main() {

        char a[] = "anna";


        if (palindromeString(a))
            printf("\nStringa palindroma");
        else
            printf("\nStringa non palindroma");

    }


    bool palindromeString(char w[]){

       int i=0, j;
       j=strlen(w)-1;

       if (strlen(w)==0)
           puts("Empty String");

       if(strlen(w)==1)
           return true;

       if(w[i]!=w[j]){
           return false;
       }else{
           palindromeString(w+1);
           j=j-1;
           printf("%d", j);
       }
       return true;
    }

