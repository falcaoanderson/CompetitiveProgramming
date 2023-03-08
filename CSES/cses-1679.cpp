// 09/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, ll> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m, grau[MAXN];
vector<int> adj[MAXN];

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        grau[b]++;
    }
    
    queue<int> fila;
    vector<int> resp;

    for(int i=1; i<=n; i++) 
        if(grau[i]==0)
            fila.push(i);

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        resp.pb(u);

        for(int v: adj[u]){
            grau[v]--;

            if(grau[v]==0) fila.push(v);
        }
    }

    if((int)resp.size()==n){
        for(int i: resp) cout << i << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
