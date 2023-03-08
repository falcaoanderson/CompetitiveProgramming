#include <cstdio>

int main(){
    int t, soma=0;
    int v[100005];

    scanf("%d",&t);

    for(int i=0; i<t; i++){
        scanf("%d",&v[i]);
        soma += v[i];
    }
    soma=soma/2;

    for(int i=0; i<t; i++){
        soma -= v[i];
        if(soma == 0){printf("%d\n",i+1);break;}
    }

    return 0;
}
