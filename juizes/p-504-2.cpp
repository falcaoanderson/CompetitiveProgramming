#include <cstdio>
int dp[100];

int fatorial(int n){
    if(dp[n]!=0){return dp[n];}

    if (n<2){return 1;}

    return dp[n] = n*fatorial(n-1);
}

int main(){
    int n,soma=0;

    for (int i=0; i<5; i++){
        scanf("%i",&n);

        if(n%3==0){soma+=fatorial(n);}
    }
    printf("%i\n",soma);

    return 0;
}
