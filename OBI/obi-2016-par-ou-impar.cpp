// 17/01/19 // 10:52 PM //

#include <cstdio>

int main(){
    int p, d1, d2;
    scanf ("%d %d %d", &p, &d1, &d2);

    if(p==0){
        if( (d1+d2)%2 == 0)
            printf("0\n");
        else
            printf("1\n");
    }
    else{
        if( (d1+d2)%2 == 0)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}

