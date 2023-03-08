// 06/1/19 // 5:50 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MAXLOG 20
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, ll> pii;

int n;
int nivel[MAXN], ancestral[MAXN][MAXLOG];
ll dist[MAXN];
vector<pii> grafo[MAXN];

void dfs(int no){
    for(auto filho : grafo[no]){

        if(nivel[filho.first] == -1){
            ancestral[filho.first][0] = no;
            nivel[filho.first]        = nivel[no] + 1;
            dist[filho.first]         = dist[no] + filho.second;

            dfs(filho.first);
        }
    }
}

void ini_nivel_ancestral(){
    memset(    nivel, -1,     sizeof(nivel));
    memset(ancestral, -1, sizeof(ancestral));
    nivel[0]        = 0;
    ancestral[0][0] = 0;
    dist[0]         = 0LL;

    dfs(0);

    for(int j=1; j<MAXLOG; j++)
        for(int i=0; i<n; i++)
            if(ancestral[i][j-1] != -1)
                ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
}

int lca(int u, int v){
    if(nivel[v]>nivel[u]) swap(u, v);

    for(int i=MAXLOG-1; i>=0; i--)
        if(nivel[ ancestral[u][i] ] >= nivel[v])
            u = ancestral[u][i];

    if(u==v) return u;

    for(int i=MAXLOG-1; i>=0; i--)
        if(ancestral[u][i]!=-1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n){

        if(n==0) break;
        for(int i=0; i<n; i++) grafo[i].clear();

        for(int i=1; i<n; i++){
            int a, l;
            cin >> a >> l;

            grafo[i].pb( mp(a, l) );
            grafo[a].pb( mp(i, l) );

        }
        ini_nivel_ancestral();


        int q;
        cin >> q;

        while(q--){
            int s, t;

            cin >> s >> t;

            int mac = lca(s,t);

            ll dsum = dist[s] + dist[t] - 2*dist[mac];

            cout << dsum << " ";
        }
        cout << "\n";

    }

    return 0;
}
