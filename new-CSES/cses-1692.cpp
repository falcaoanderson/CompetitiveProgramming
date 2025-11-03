/*
16/09/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n;
vector<int> adj[(1<<14)+5], resp;

void dfs(int u){
    while(!adj[u].empty()){
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }
    resp.PB(u);
}

int main(){
    fast_io;
    
    cin >> n;

    if(n==1){
        cout << "01" << endl;
        return 0;
    }

    for(int i=0; i<(1<<(n-1)); i++){
        int aux = i;
        
        if((aux&(1<<(n-2))) != 0) aux ^= (1<<(n-2));

        adj[i].PB((aux<<1));
        adj[i].PB((aux<<1) + 1);
    }

    // for(int i=0; i<(1<<(n-1)); i++){
    //     cout << i << ": ";
    //     for(int v: adj[i]) cout << v << " ";
    //     cout << endl;
    // }

    dfs(0);
    for(int i=n-2; i>=0; i--){
        cout << (resp[SZ(resp)-1]&(1<<i));
    }
    for(int i=SZ(resp)-2; i>=0; i--){
        cout << (resp[i]&1);
    }
    cout << endl;

    return 0;
}
