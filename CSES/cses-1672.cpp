// 04/11/20 // 10:03 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (5e2) + 10;

int n, q, m;
ll dist[MAXN][MAXN];

int main(){
    fast_io;
    
    cin >> n >> m >> q;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            dist[i][j] = INF;

    while(m--){
        int a, b;
        ll c;
        
        cin >> a >> b >> c;
        
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    while(q--){
        int a, b;
        cin >> a >> b;
        
        if(a==b) cout << 0 << endl;
        else cout << (dist[a][b]!=INF?dist[a][b]:-1) << endl;
    }

    return 0;
}
