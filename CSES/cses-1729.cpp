// 22/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

const int MAXN = 1e6 + 10;
const int MAXK = 1e2 + 10;

int n, k;
int memo[MAXN][2], qnt[MAXK];

int solve(int falta, int jogador){

    if(memo[falta][jogador]!=-1) return memo[falta][jogador];

    if(falta==0) return ~jogador&1;

    int resp0 = 1, resp1 = 0;

    if(jogador==0){
        for(int i=1; i<=k && falta-qnt[i]>=0; i++)
            resp0 =  min(resp0, solve(falta-qnt[i], ~jogador&1));
        
        memo[falta][jogador] = resp0;
    }
    if(jogador==1){
        for(int i=1; i<=k && falta-qnt[i]>=0; i++)
            resp1 =  max(resp1, solve(falta-qnt[i], ~jogador&1));

        memo[falta][jogador] = resp1;
    }
    
    return memo[falta][jogador];
}

int main(){
    fast_io;

    cin >> n >> k;
    for(int i=1; i<=k; i++) cin >> qnt[i];
    
    sort(qnt+1, qnt+k+1);
    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++){
        if(!solve(i, 0)) cout << 'W';
        else cout << 'L';
    }   
    cout << endl;

    return 0;
}
