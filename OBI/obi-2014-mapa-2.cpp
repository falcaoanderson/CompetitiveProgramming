// 22/10/20 // 8:36 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

ll n;
bool visitado[MAXN];
vector<pair<int, bool>> grafo[MAXN];

int dfs(int u){
    visitado[u] = 1;

    int temp = 1;
    for(auto v: grafo[u])
        if(!visitado[v.first] && v.second==0)
            temp += dfs(v.first);

    return temp;
}

int main(){
    fast_io;

    cin >> n;

    for(int i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        grafo[a].pb(mp(b, c));
        grafo[b].pb(mp(a, c));
    }

    ll total = (n*(n-1))/2;

    for(int i=1; i<=n; i++)
        if(!visitado[i]){
            ll qnt = dfs(i);
            total -= (qnt*(qnt-1))/2;
        }

    cout << total << endl;

    return 0;
}
