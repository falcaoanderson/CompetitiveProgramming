// 08/02/19 // 7:23 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1010
#define MAXV 1010

int n, valor;
int moedas[MAXN];
int memo[MAXN][MAXV];

char saida='N';
void troco(int i, int val){
    if(i>n || val<0) return;

    if(memo[i][val]>=0) return;

    memo[i][val]=1;

    if(val==0){
        saida='S';
        return;
    }

    troco(i, val - moedas[i]);
    troco(i+1, val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n >> valor;
    for(int i=1; i<=n; i++) cin >> moedas[i];

    troco(1, valor);

    cout << saida << "\n";

    return 0;
}


