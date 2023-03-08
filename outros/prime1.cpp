#include <cstdio>
#include <cmath>
#define MAXN 1000000005

char din[MAXN];

bool primo(int n){ // 0 = nao calculado // '1' = false // '2' = true //
    if(n==1)return false;
    if(n==2)return true;

    if(int(din[n])!=0){
        if(din[n]=='1')return false;
        if(din[n]=='2')return true;
    }

    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            din[n]='1';
            return false;
        }
    }

    din[n]='2';
    return true;
}

int main(){
    int t, s, e;
    scanf("%d",&t);

    for(int i=0; i<t; i++){
        scanf("%d%d", &s, &e);

        for(int j=s; j<=e; j++){
            if(primo(j)) printf("%d\n",j);
        }
        printf("\n");
    }

    return 0;
}
