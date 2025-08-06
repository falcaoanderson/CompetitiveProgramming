/*
06/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int parent[MAXN];
bool val[MAXN];
vector<int> child[MAXN], resp;

void dfs(int u){
    bool flag = val[u];

    for(int v: child[u]){
        dfs(v);

        flag = (flag && val[v]);
    }

    if(flag){
        resp.PB(u);
    }
}

int main(){
    fast_io;

    int n;
    cin >> n;

    int root=0;
    for(int i=1; i<=n; i++){
        int p, c;
        cin >> p >> c;

        parent[i] = p;
        val[i] = c;

        if(p==-1){
            root = i;
        }
        else{
            child[p].PB(i);
        }
    }

    dfs(root);

    if(resp.empty()){
        cout << -1 << endl;
    }
    else{
        sort(resp.begin(), resp.end());
        for(int x: resp) cout << x << " ";
        cout << endl;
    }

    return 0;
}
