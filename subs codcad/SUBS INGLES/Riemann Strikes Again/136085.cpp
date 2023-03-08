// 15/01/19// 6:27 PM //

#include <cstdio>

#define MAXN 1300000 // raiz ~ 1140 //

bool primos[MAXN];
int  posicao[MAXN];

int n, p, cont=1;

void  crivo(){
    for(int i=2; i<=1140; i++){
        if(!primos[i]){
            for(int j=i*i; j<=MAXN; j+=i){
                primos[j]=1;
            }
        }
    }
}

int main(){

    scanf("%d", &n);

    crivo();

    posicao[2]=1;
    for(int i=3; i<=MAXN; i+=2){
        if(!primos[i]){
            cont++;
            posicao[i]=cont;
        }
    }

    for(int i=0; i<n; i++){
        scanf("%d", &p);
        printf("%d\n", posicao[p]);
    }

    return 0;
}

