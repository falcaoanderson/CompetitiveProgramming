#include <stdio.h>

void main(void){
    int v[10010];
    int n, maior, temp=0, a, b, cont=1, i, j;

    while(scanf("%d",&n) && n!=0){

        for(i=0; i<n; i++){
            scanf("%d%d", &a, &b);
            v[i] = a-b;
        }

        maior=-51;

        for(i=0; i<n; i++){
            for(j=i; j<n; j++){
                temp += v[j];
                if(temp>maior){
                    maior = temp;
                    a = i; b = j;
                }
                else if( temp==maior && (j-i)>(b-a) ){
                    a = i; b = j;
                }
            }
            temp = 0;
        }

        printf("Teste %d\n",cont);
        if(maior<=0){printf("nenhum\n\n");}
        else{printf("%d %d\n\n",a+1,b+1);}
        cont++;
    }

}
