/*
28/08/25 

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

int bit[MAXN];
int sum(int i){
    int resp = 0;
    while(i>0){
        resp += bit[i];
        resp %= MOD;
        i -= (i&-i);
    }
    return resp;
}
void update(int i, int val){
    while(i<=(int)2e5){
        bit[i] += val;
        bit[i] %= MOD;
        i += (i&-i);
    }
}

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n+1);
    map<int, int> compress;
    for(int i=0; i<n; i++){
        cin >> v[i];
        compress[v[i]] = 0;
    }
    int aux=0;
    for(auto &p: compress){
        p.second = (++aux);
    }
    
    ll resp = 0;
    for(int i=0; i<n; i++){
        int val = compress[v[i]];
        int crr = (1 + sum(val-1))%MOD;
        
        resp = (resp + crr)%MOD;

        update(val, crr);
    }

    cout << resp << endl;
    
    return 0;
}
