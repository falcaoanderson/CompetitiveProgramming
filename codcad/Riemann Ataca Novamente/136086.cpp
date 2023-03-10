// 15/01/19// 6:27 PM //

#include <iostream>
using namespace std;

#define MAXN 1300100 // raiz ~ 1140 //

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    crivo();

    posicao[2]=1;
    for(int i=3; i<=MAXN; i+=2){
        if(!primos[i]){
            cont++;
            posicao[i]=cont;
        }
    }


    for(int i=0; i<n; i++){
        cin >> p;
        cout << posicao[p] << "\n";
    }


    return 0;
}

