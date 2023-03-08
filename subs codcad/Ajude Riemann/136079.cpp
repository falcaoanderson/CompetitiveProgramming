// 15/01/19// 5:12 PM //

#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 15485870 // 15485863 -- sqrt = 3935

bool primos[MAXN];
int n, cont=0;

void  crivo(){
    int maior = n*log(log(n)) + n*log(n)+1;
    if(maior>MAXN) maior=MAXN;
    if(n<=6) maior = 13;

    for(int i=2; i<=maior; i++){
        if(!primos[i]){
            cont++;
            if(cont==n){
                cout << i << "\n";
                return;
            }
            for(int j=i; j<=maior; j+=i){
                primos[j]=1;
            }
        }
    }
}

int main(){

    cin >> n;

    if(n==1){cout << "2\n"; return 0;}

    crivo();


    return 0;
}
