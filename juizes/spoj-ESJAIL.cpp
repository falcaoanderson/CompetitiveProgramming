// 24/01/24
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
#include <stack>
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

bool visited[MAXN], door[MAXN], key[MAXN];
int chamber_key[MAXN], chamber_door[MAXN];
vector<int> adj[MAXN];

void dfs(int u){
    visited[u] = 1;

    if(chamber_door[u]!=0){
        key[u] = 1;

        if(door[chamber_door[u]] && !visited[chamber_door[u]]){
            dfs(chamber_door[u]);
        }
    }

    for(int v: adj[u]){
        if(visited[v]) continue;

        if(chamber_key[v]==0){
            dfs(v);
        }
        else{
            door[v] = 1;

            if(key[chamber_key[v]]){
                dfs(v);
            }
        }
    }
}

int main(){
    fast_io;

    while(true){
        int n, k, m;
        cin >> n >> k >> m;
        
        if(n==-1) break;

        for(int i=1; i<=n; i++) adj[i].clear();
        memset(chamber_door, 0, sizeof(chamber_door));
        memset(chamber_key, 0, sizeof(chamber_key));
        memset(visited, 0, sizeof(visited));
        memset(door, 0, sizeof(door));
        memset(key, 0, sizeof(key));

        for(int i=0; i<k; i++){
            int a, b;
            cin >> b >> a;

            chamber_key[a]  = b; // a chave que abre a porta 'a' esta na sala 'b'
            chamber_door[b]  = a; //a porta que a chave 'b' abre esta na sala 'a'
        }   

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            adj[a].PB(b);
            adj[b].PB(a);
        }

        dfs(1);

        if(visited[n]){
            cout << "Y" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }

    return 0;
}
