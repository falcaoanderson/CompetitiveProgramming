#include <stdio.h>

int main(){
    char numero[6];

    scanf("%s",&numero);

    if((numero[0]-'0')%2==0){
        printf("%d\n",atoi(numero)-4);
    }else{
        printf("%d\n",atoi(numero)-3);
    }
    return 0;
}

