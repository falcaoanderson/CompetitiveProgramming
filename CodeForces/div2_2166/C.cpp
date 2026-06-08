/*
16/11/25 

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
const int MOD  = (1e9) + 7;

int nv[MAXN], st[MAXN][25];

int qmax(int l, int r){
    int logl = log2(r-l+1);

    if(nv[ st[l][logl] ] < nv[ st[r-(1<<logl)+1][logl] ]){
        return st[r-(1<<logl)+1][logl];
    }
    else{
        return st[l][logl];
    }
}

ll solve(int l, int r){
    if(l>=r) return 0;
    if(l+1==r) return max(nv[l], nv[r]);

    int max_idx = qmax(l, r);

    ll resp = 0;
    if(l <= max_idx - 1) resp += (ll)nv[max_idx] + solve(l, max_idx - 1);
    if(max_idx + 1 <= r) resp += (ll)nv[max_idx] + solve(max_idx + 1, r);

    return resp;
}

void sol(){
    int n;
    cin >> n;

    int max_idx = -1;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];

        if(max_idx==-1 || v[max_idx] < v[i]){
            max_idx = i;
        }
    }

    for(int i=max_idx+1; i<n; i++) nv[i - max_idx - 1] = v[i];
    for(int i=0; i<max_idx; i++) nv[i + n - max_idx - 1] = v[i];
    
    int logn = log2(n-1);
    for(int i=0; i<n; i++) st[i][0] = i;
    for(int k=1; k<=logn; k++){
        for(int i=0; i<n && i+(1<<k)-1 < n; i++){
            if(nv[st[i][k-1]] < nv[st[i+(1<<(k-1))][k-1]]){
                st[i][k] = st[i+(1<<(k-1))][k-1];
            }
            else{
                st[i][k] = st[i][k-1];
            }
        }
    }

    cout << (ll)v[max_idx] + solve(0, n-2) << endl;
}  

int main(){
    fast_io;

    int t;
    cin >> t;
    
    while(t--){
        sol();
    }
    
    return 0;
}
