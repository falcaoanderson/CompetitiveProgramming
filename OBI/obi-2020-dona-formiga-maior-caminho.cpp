// 20/08/21 // 8:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e2) + 10;

int s, t, p;
int altura[MAXN], maior[MAXN];
vector<int> grafo[MAXN];

int dfs(int u){
    if(maior[u]!=-1) return maior[u];

    maior[u] = 0;

    for(int v : grafo[u]){
        if(altura[u] > altura[v])
            maior[u] = max(maior[u], 1 + dfs(v));
    }

    return maior[u];
}

int main(){
    fast_io;

    cin >> s >> t >> p;

    for(int i=1; i<=s; i++) cin >> altura[i];
    for(int i=1; i<=t; i++){
        int a, b; cin >> a >> b;

        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    memset(maior, -1, sizeof(maior));

    cout << dfs(p) << endl;

    return 0;
}
