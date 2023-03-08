// 17/09/19 // 8:45 PM //

#include <bits/stdc++.h>

using namespace std;

int main(){
    int v, n, aux;

    scanf("%d%d",&v,&n);

    for(int i=1; i<=8; i++){
        printf("%d ", (int)ceil(i*n*v*0.1));
    }
    printf("%d\n", (int)ceil(9*n*v*0.1));


    return 0;
}
