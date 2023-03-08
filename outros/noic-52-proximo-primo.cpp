// 04/04/2019 // 8:38 PM //

#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 1000000000
#define RAIZ (sqrt(2*MAXN)+1)

bool primos[2*MAXN];

void crivo(){
    primos[1] = 1;

    for(int i=2; i<=RAIZ; i++){

        if(!primos[i]){
            for(int j=i*i; j<=2*MAXN; j+=i)
                primos[j] = 1;
        }

    }
}

int main(){

    crivo();

    //for(int i=1; i<=2*MAXN; i++)
     //   if(!primos[i])
        //    cout << i << " ";

    return 0;
}
