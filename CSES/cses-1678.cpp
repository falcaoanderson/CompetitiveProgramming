// 08/11/20 // xx:xx PM //
// 09/11/20 // 3:30 PM //   
 
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
 
int n, m, visitado[MAXN], ant[MAXN];
vector<int> adj[MAXN];
int ini, fim;

bool dfs(int u){
    visitado[u] = 1;

    for(int v: adj[u]){
        if(visitado[v]==0){ 
            ant[v] = u;
            if(dfs(v)) return true;
        }
        else if(visitado[v]==1){ // achei um ciclo
            ini = v;
            fim = u;
            return true;
        }
    }

    visitado[u] = 2;
    return false;
}
 
int main(){
    fast_io;
    
    cin >> n >> m;
 
    while(m--){
        int a, b;
        cin >> a >> b;
 
        adj[a].pb(b);
    }    
    
    for(int i=1; i<=n; i++){
        if(visitado[i]==0 && dfs(i)){
            stack<int> caminho;
            caminho.push(ini);
            while(fim!=ini){
                caminho.push(fim);
                fim = ant[fim];
            }
            caminho.push(ini);
            cout << caminho.size() << endl;
            while(!caminho.empty()){
                cout << caminho.top() << " ";
                caminho.pop();
            }
            cout << endl;

            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;

    return 0;
}