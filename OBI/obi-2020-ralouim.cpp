#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = (2e3) + 10;
const int INF = 0x3f3f3f3f;

int n;
int grafo[MAXN][MAXN], memo[MAXN][MAXN];
pair<int, int> tendas[MAXN];

int dfs(int atual, int ant){
    if(memo[atual][ant]!=-1) return memo[atual][ant];

    memo[atual][ant] = 0;

    for(int i=1; i<=n; i++){
        if(i==atual || grafo[atual][i] >= grafo[ant][atual]) continue;

        memo[atual][ant] = max(memo[atual][ant], (int)(i!=0) + dfs(i, atual));
    }

    return memo[atual][ant];
}   

int main(){
    fast_io;

    cin >> n;
    
    tendas[0] = {0, 0};
    for(int i=1; i<=n; i++) cin >> tendas[i].first >> tendas[i].second;
    
    
    for(int i=0; i<=n; i++)
        for(int j=i+1; j<=n; j++){
            grafo[i][j] = grafo[j][i] = (tendas[i].first-tendas[j].first)*(tendas[i].first-tendas[j].first)
                                       +(tendas[i].second-tendas[j].second)*(tendas[i].second-tendas[j].second);
            //cout << i <<" " << j << " " << grafo[i][j] << endl;
        }
        
    grafo[0][0] = INF;
    memset(memo, -1, sizeof(memo));

    cout << dfs(0, 0) << endl;

    return 0;
}
