// 22/10/20 //  8:05 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;

int n, d;
int xx[MAXN], yy[MAXN];
bool visitado[MAXN];
vector<pair<int, int>> grafo[MAXN];

void dfs(int u){
    visitado[u] = 1;

    for(auto v: grafo[u])
        if(!visitado[v.first] && v.second<=d)
            dfs(v.first);
}

int main(){
    fast_io;

    cin >> n >> d;
    d *= d;

    for(int i=1; i<=n; i++)
        cin >> xx[i] >> yy[i];

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int td = (xx[i]-xx[j])*(xx[i]-xx[j]) + (yy[i]-yy[j])*(yy[i]-yy[j]);

            grafo[i].pb(mp(j, td));
            grafo[j].pb(mp(i, td));
        }
    }

    dfs(1);
    bool resp = 1;

    for(int i=1; i<=n; i++)
        if(!visitado[i]){
            resp = 0;
            break;
        }

    if(resp)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}

