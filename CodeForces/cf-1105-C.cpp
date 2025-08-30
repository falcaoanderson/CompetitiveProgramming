/*
30/08/25 

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
const int MAXN = (2e5) + 5;
const ll MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, l, r;
    cin >> n >> l >> r;
    
    vector<ll> v(3);
    int aux = (r-l+1); 
    v[0] = v[1] = v[2] = aux/3;
    if(aux%3>0) v[l%3]++;
    if(aux%3>1) v[(l+1)%3]++;

    vector<vector<ll>> solve(n, vector<ll>(3));

    for(int i=0; i<3; i++) solve[0][i] = v[i];
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                solve[i][j] += (solve[i-1][k] * v[(j-k+3)%3])%MOD;
                solve[i][j] %= MOD;
            }
        }
    }

    cout << solve[n-1][0] << endl;

    return 0;
}
