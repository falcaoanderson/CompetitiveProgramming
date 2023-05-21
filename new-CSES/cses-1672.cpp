// 21/05/23 // Floyd-Warshall // O(n^3)
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

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (5e2) + 5;

ll dist[MAXN][MAXN];

int main(){
    fast_io;

    int n, m, q;
    cin >> n >> m >> q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = ( i==j? 0LL: INF );
        }
    }

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = dist[b][a] = min(dist[a][b], (ll)c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        if(dist[a][b]==INF) cout << -1 << endl;
        else                cout << dist[a][b] << endl;
    }

    return 0;
}
