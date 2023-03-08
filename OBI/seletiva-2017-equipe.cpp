// 07/06/19 // 6:24 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 210
#define MAXK 20
#define ALL ((1<<k)-1)
#define MAXMASK 1025
#define INF 1000

int n, k;
int mask[MAXN];
int memo[MAXN][MAXMASK][MAXMASK];

int funcao(int i, int uniao, int inter){
    if(memo[i][uniao][inter]>=0) return memo[i][uniao][inter];

    if(uniao==0 && i<=n)
        return memo[i][uniao][inter] =
        min( 1+funcao(i+1,mask[i],mask[i]), funcao(i+1, 0, 0) );

    if(uniao==ALL && inter==0) return 0; // se eu achei um solucao

    if(i>n) return INF;                  // se nao achei descarto


    return memo[i][uniao][inter] =
    min( 1+funcao(i+1, uniao|mask[i], inter&mask[i]), funcao(i+1, uniao, inter) );

}

int main(){

    memset(memo, -1, sizeof(memo));

    cin >> n >> k;

    for(int i=1, qnt, bit; i<=n; i++){
        cin >> qnt;

        for(int j=0; j<qnt; j++){
            cin >> bit;

            mask[i] |= (1<<(bit-1));
        }
    }

    int resp = funcao(1, 0, 0);

    if(resp<INF)
        cout << resp << "\n";
    else
        cout << "-1\n";

    return 0;
}
