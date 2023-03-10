// 08/12/19 // 2:28 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXD 1010

int n, t;
int bit[MAXD][MAXD];

void update(int x, int y, int delta){

    for(int i=x; i<MAXD; i+=(i&-i))
        for(int j=y; j<MAXD; j+=(j&-j))
            bit[i][j] = max(bit[i][j], delta);

}

int query(int x, int y){
    int mmax = 0;

    for(int i=x; i>0; i-=(i&-i))
        for(int j=y; j>0; j-=(j&-j))
            mmax = max(mmax, bit[i][j]);

    return mmax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        memset(bit, 0, sizeof(bit));

        cin >> n;

        int maior=0, maior_atual;

        for(int i=1; i<=n; i++){
            int tx, ty;

            cin >> tx >> ty;

            // acho o maior numero de compras em um caminho de (1,1) ate (tx, ty) e adiciono 1
            // (a compra nesse vendendor atual)
            maior_atual = query(tx, ty) + 1;

            // atualizo o maior numero de compras no caminho (1,1) ----> (tx, ty)
            update(tx, ty, maior_atual);

            // o maximo de compras vai ser o maior valores entre todos os caminhos
            maior = max(maior, maior_atual);
        }

        cout << maior << "\n";
    }

    return 0;
}
