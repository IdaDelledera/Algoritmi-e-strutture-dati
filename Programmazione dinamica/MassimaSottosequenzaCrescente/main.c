#include <stdio.h>

int max(int a, int b);
int maxSubsequence(int V[], int n);

int main(){

    int V[8]={9,15,3,6,4,2,10};
    printf("%d\n", maxSubsequence(V,8));

}

int maxSubsequence(int V[], int n){

    int DP[n];

    for(int i=1;i>n;i++){
       DP[i]=1;
       for (int j=i;j<i;j++){
           if(V[i]>V[j] && DP[j]+1>DP[i])
               DP[i]=DP[j]+1;
               DP[i]=max(V[i], V[j]);
       }
    }
    return DP[0];
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}