// 13/01/2019 // 6:47 PM //

// edit // 04/03/2019 // 10:19 PM //

#include <cstdio>
using namespace std;

int main(){

    int a, b, c, d; // a=divisor // b=nao divisor // c=multiplo // d=nao multiplo//

    scanf("%d%d%d%d", &a, &b, &c, &d);

    for(int i=a+a; i*i<=a*c; i+=a){
        if(i%b!=0 && c%i==0 && d%i!=0){
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}
