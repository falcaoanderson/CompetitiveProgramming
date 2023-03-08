// 04/11/20 // 5:18 PM //

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

int n, m;
vector<int> adj[MAXN];
int color[MAXN];

void paint(int x){
    queue<int> qq;
    qq.push(x);
    color[x] = 0;

    while(!qq.empty()){
        int u = qq.front();
        qq.pop();

        for(int v: adj[u])
            if(color[v]==-1){
                color[v] = ~color[u]&1;
                
                qq.push(v);
            }
    }
}

int main(){
    fast_io;
    
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    memset(color, -1, sizeof(color));

    for(int i=1; i<=n; i++)
        if(color[i]==-1) paint(i);

    bool flag = 1;

    for(int u=1; u<=n; u++){
        for(int v: adj[u]){
            if(color[u]==color[v]){
                flag  = 0;
                break;
            }
        }

        if(!flag) break;
    }

    if(!flag) 
        cout << "IMPOSSIBLE";
    else 
        for(int u=1; u<=n; u++) cout << color[u]+1 << " ";

    cout << endl;

    return 0;
}
