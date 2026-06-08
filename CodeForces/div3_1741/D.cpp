/*
24/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 262144 + 5;
const int INF = 0x3f3f3f3f;

int n, v[MAXN];
int minv[4*MAXN], maxv[4*MAXN], cost[4*MAXN];

void build(int node, int l, int r){
    if(l==r){
        cost[node] = 0;
        minv[node] = maxv[node] = v[l];
        return;
    }
    int mid = (l+r)/2, left = 2*node, right = 2*node+1;

    build(left, l, mid);
    build(right, mid+1, r);

    if(cost[left] >= INF || cost[right] >= INF){
        cost[node] = INF;
        return;
    }

    if(maxv[left]+1 == minv[right]){
        cost[node] = cost[left] + cost[right];
    }
    else if(maxv[right]+1 == minv[left]){
        cost[node] = cost[left] + cost[right] + 1;
    }
    else{
        cost[node] = INF;
    }
    minv[node] = min(minv[left], minv[right]);
    maxv[node] = max(maxv[left], maxv[right]);
}


void solve(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    build(1, 1, n);

    cout << (cost[1] < INF ? cost[1]: -1) << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}