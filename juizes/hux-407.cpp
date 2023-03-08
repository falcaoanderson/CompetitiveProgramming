#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 1000010

int memo[MAXN];

int funcao(int n){
    if(memo[n]!=-1)return memo[n];

    if(n%2==0)return memo[n] = 1 + funcao(n/2);
    return memo[n] = 1 + funcao(n*3+1);
}

int main(){
    memset(memo, -1, sizeof(memo));
    memo[1]=1;

    int i, j, maior;
    int x , y;

    while(scanf("%d%d",&i,&j)!=EOF){
        x=i; y=j;
        if(x>j)swap(x,y);

        maior=-1;

        for(int k=x; k<=y; k++)
            if(funcao(k)>maior)maior=funcao(k);

        printf("%d %d %d\n", i, j, maior);
    }

    return 0;
}
