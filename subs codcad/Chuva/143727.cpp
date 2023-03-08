// 06/04/2019 // 4:13 PM //

#include <iostream>

using namespace std;

#define MAXN 100010

int n;
int piscina[MAXN];
int direita[MAXN], esquerda[MAXN], res[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> piscina[i];

    int maior=piscina[1];

    for(int i=1; i<=n; i++){
        if(piscina[i]<maior){
            direita[i] = direita[i-1] + 1;
        }
        else{
            direita[i] = 0;
            maior = piscina[i];
        }
    }
    maior = piscina[n];
    for(int i=n; i>=0; i--){
        if(piscina[i]<maior){
            esquerda[i] = esquerda[i+1] + 1;
        }
        else{
            esquerda[i] = 0;
            maior = piscina[i];
        }
    }

    int saida = 0;

    for(int i=1; i<=n; i++){
        if(esquerda[i]!=0 && direita[i]!=0)
            res[i] = res[i-1] + 1;
        else{
            res[i] = 0;
            saida += res[i-1];
        }
    }

    cout << saida << "\n";

    return 0;
}
