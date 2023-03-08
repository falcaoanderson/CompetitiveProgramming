#include <stdio.h>
#include <string.h>

int funcao(int n){
    int cont=1;

    while(n!=1){
        if(n%2==0)n=n/2;
        else n=n*3+1;
        cont++;
    }

    return cont;
}

void main(void){
    int i, j, maior;
    int x , y, temp, k;

    while(scanf("%d%d",&i,&j)!=EOF){
        x=i; y=j;
        if(x>j){
            temp=x;
            x=y;
            y=temp;
        }

        maior=-1;

        for(k=x; k<=y; k++)
            if(funcao(k)>maior)maior=funcao(k);

        printf("%d %d %d\n", i, j, maior);
    }

}
