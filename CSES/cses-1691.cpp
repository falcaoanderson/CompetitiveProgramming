// 11/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m, grau[MAXN];
vector<int> path;
set<int> adj[MAXN];

void eulerian(){
    stack<int> pilha;
    pilha.push(1);

    while(!pilha.empty()){
        int u = pilha.top();

        if(adj[u].empty()){
            path.pb(u);
            pilha.pop();
        }
        else{
            auto it = adj[u].begin();
            int v = *it;

            adj[u].erase(it);
            adj[v].erase(u);

            pilha.push(v);
        }
    }
}

int main(){
    fast_io;
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].insert(b);
        adj[b].insert(a);

        grau[a]++; grau[b]++;
    }

    int qnt_impar = 0;
    for(int i=1; i<=n; i++)
        if(grau[i]&1) qnt_impar++;
    
    if(qnt_impar==0){
        eulerian();

        if((int)path.size()!=m+1){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        for(int u: path)
            cout << u << " ";
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
