// 13/09/23 //
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

const int MAXN =  25;
const int MAXMASK = (1<<20)+5;
const int MOD  = (1e9) + 7;

ll adj[MAXN][MAXN];
int n;
ll memo[MAXN][MAXMASK];

int solve(int u, int mask){
    if(memo[u][mask]!=-1) return memo[u][mask];

    if(mask == (1<<n)-1) return memo[u][mask] = (u==n-1);
    if((mask&(1<<(n-1)))!=0) return memo[u][mask] = 0;

    memo[u][mask] = 0;
    for(int v=0; v<n; v++){
        if( ((1<<v)&mask)==0 && adj[u][v]>0){
            memo[u][mask] = memo[u][mask] + (adj[u][v] * solve(v, mask|(1<<v)))%MOD;
            memo[u][mask] %= MOD;
        }
    }

    return memo[u][mask];
}

int main(){
    fast_io;

    int m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        
        a--; b--;
        adj[a][b]++;
    }

    memset(memo, -1, sizeof(memo));
    cout << solve(0, 1) << endl;

    return 0;
}
