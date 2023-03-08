// 08/02/19 // 7:42 PM //

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1010
#define INF 999999

int n, valor;
int moedas[MAXN];
int memo[MAXN][MAXN];

int troco(int i, int val){

    if(memo[i][val]>=0) return memo[i][val];

    if(i>n || val<0) return INF;

    if(val==0) return 0;

    if(val-moedas[i]>=0){
        return memo[i][val] = min( 1 + troco(i, val-moedas[i]), troco(i+1, val) );
    }

    return memo[i][val] = troco(i+1, val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n >> valor;
    for(int i=1; i<=n; i++) cin >> moedas[i];

    int total = 0;

    for(int i=valor-1; i>=1; i--){
        if(memo[1][i]==-1) troco(1,i);

        if(memo[1][i]>=INF) total++;
    }

    cout << total << "\n";


    return 0;
}
