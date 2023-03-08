// 22/03/2020 // 4:14 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = (int)(2e5) + 10;

int n, m;
vector<int> grafo[MAXN];
int visitado[MAXN];

bool dfs(int v){
    visitado[v] = 1;

    bool temp = false;

    for(int adj : grafo[v]){
        if(visitado[adj]==1) return true;

        if(visitado[adj]==0) temp = (temp || dfs(adj));
    }

    visitado[v] = 2;

    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int sol = -1;

    for(int k=1; k<=m; k++){
        int u, l, r;
        cin >> u >> l >> r;

        if(sol!=-1) continue;

        for(int i=l; i<=r; i++) grafo[u].pb(i);

        memset(visitado, 0, sizeof(visitado));

        for(int i=1; i<=n; i++)
            if(visitado[i]==0 && dfs(i)){
                sol = k;
                break;
            }
    }

    cout << sol << endl;

    return 0;
}
