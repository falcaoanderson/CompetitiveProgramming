// 01/08/19 // 3:27 PM //

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1010
#define INF 0x3f3f3f3f

struct Caixa{
    int peso, resistencia, test;
};

int n;
Caixa caixas[MAXN];

int memo[MAXN][MAXN];

bool ordCaixa(Caixa a, Caixa b){
    return (a.resistencia > b.resistencia || (a.resistencia == b.resistencia && a.peso>b.peso));
}

bool ordCaixa_test(Caixa a, Caixa b){
    return (a.test > b.test || (a.test == b.test && a.peso>b.peso));
}

void sol(){
    for(int i=0; i<=n; i++){
        memo[i][0]   = INF; // uma pilha de altura 0 tem resistencia infinita
        memo[0][i+1] = -1;  // uma pilha com 0 caixas e altura positiva tem resistencia negativa (impossivel)
    }

    for(int i=1; i<=n; i++)
        for(int h=1; h<=n; h++){
            int pegar, naopegar;

            naopegar = memo[i-1][h];
            pegar    = min(caixas[i].resistencia, memo[i-1][h-1]-caixas[i].peso);

            memo[i][h] = max(naopegar, pegar);
        }

}

void print(){
    cout << "\n";
    for(int i=1; i<=n; i++){
        for(int h=1; h<=n; h++){
            cout << memo[i][h] << " ";
        }
        cout << "\n";
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> caixas[i].peso >> caixas[i].test;
        caixas[i].resistencia = caixas[i].test - caixas[i].peso;
    }

    sort(caixas+1, caixas+n+1, ordCaixa_test);

    sol();

    for(int h=n; h>=0; h--)
        if(memo[n][h]>=0){
            cout << h << "\n";
            break;
        }

    //print();

    return 0;
}
