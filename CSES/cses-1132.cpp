// 20/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int MAXN = (2e5) + 10;

int n;
vector<int> adj[MAXN];
int dist1[MAXN], dist2[MAXN], distp[MAXN], no1[MAXN], no2[MAXN];

void dfs(int u, int pa){
    for(int v: adj[u]){
        if(v==pa) continue;

        dfs(v, u);

        int distv = dist1[v] + 1;

        if(distv > dist1[u]){
            dist2[u] = dist1[u];
            no2[u] = no1[u];

            dist1[u] = distv;
            no1[u] = v;
        }
        else if(distv > dist2[u]){
            dist2[u] = distv;
            no2[u] = v;
        }
    }
}

void dfs2(int u, int pa){

    if(no1[pa]!=u && u!=1){
        distp[u] = max(distp[pa], dist1[pa]) + 1;
    }
    else if(u!=1){
        distp[u] = max(distp[pa], dist2[pa]) + 1;
    }

    for(int v: adj[u])
        if(v!=pa) dfs2(v, u);
}


int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for(int i=1; i<=n; i++)
        cout << max(dist1[i], distp[i]) << " ";
    cout << endl;

    return 0;
}
