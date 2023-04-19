// 19/04/23 // dp iterativa com otimizacao de memorias
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int MAXN = 5e3+5;

ll solve[5][MAXN]; 

/*
int n, v[MAXN];
ll dp(int a, int b){
    if(solve[a][b]!=-1) return solve[a][b];

    if(a>b) return 0;

    if(((b-a+1)&1) == (n&1)){ // primeiro joga
        return solve[a][b] = max(v[a] + dp(a+1, b), v[b] + dp(a, b-1));
    }

    // segundo joga
    return solve[a][b] = min(dp(a+1, b), dp(a, b-1));
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> v(n+1);

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    // solve[i][j] = pontuacao maxima que o primeiro jogador consegue jogando no intervalo (i, j) da lista
    
    for(int i=n; i>=1; i--){
        for(int j=i; j<=n; j++){
            if(((j-i+1)&1) == (n&1)){ // primeiro jogador joga
                solve[i&1][j] = max(v[i] + solve[~i&1][j], v[j] + solve[i&1][j-1]);   
            }
            else{ //segundo jogador joga
                solve[i&1][j] = min(solve[~i&1][j], solve[i&1][j-1]);
            }
        }
    }
    
    cout << solve[1][n] << endl;
    
    //memset(solve, -1, sizeof(solve));
    //cout << dp(1, n) << endl;

    return 0;
}