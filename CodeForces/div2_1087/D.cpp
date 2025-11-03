/*
25/10/25 

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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    double s;
    vector<int> degree(n+1);
    
    cin >> n >> s;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;

        degree[u]++;
        degree[v]++;
    }

    int f=0;
    for(int i=1; i<=n; i++){
        f += (int)(degree[i]==1);
    }
    
    cout.precision(16); 
    cout.setf(ios_base::fixed);
    cout <<  2.0 * (s / (double)f) << endl;

    return 0;
}
