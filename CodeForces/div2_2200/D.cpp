/*
27/02/26 

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


void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a, b, c;
    int minb = INF;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        if(i < x){
            a.PB(val);
        }
        else if(i < y){
            b.PB(val);
            minb = min(minb, val);
        }
        else{
            c.PB(val);
        }
    }

    vector<int> auxb;
    int idx = -1;
    for(int i=0; i<SZ(b) && idx==-1; i++){
        if(b[i] == minb) idx = i;
    }
    for(int i=idx; i<SZ(b); i++) auxb.PB(b[i]);
    for(int i=0; i<idx; i++) auxb.PB(b[i]);
    swap(auxb, b);

    if(a.empty() && c.empty()){
        for(int k: b) cout << k << " ";
        cout << endl;
        return;
    }

    idx = SZ(c);
    vector<int> op1;
    for(int k: a) op1.PB(k);
    for(int i=0; i<SZ(c); i++){
        if(c[i] < minb){ 
            op1.PB(c[i]);
        }
        else{
            idx=i; 
            break;
        }
    }
    for(int k: b) op1.PB(k);
    for(int i=idx; i<SZ(c); i++){
        op1.PB(c[i]);
    }

    vector<int> op2;
    idx = SZ(a);
    for(int i=0; i<SZ(a); i++){
        if(a[i] < minb){ 
            op2.PB(a[i]);
        }
        else{
            idx = i;
            break;
        }
    }
    for(int k: b) op2.PB(k);
    for(int i=idx; i<SZ(a); i++){
        op2.PB(a[i]);
    }
    for(int k: c) op2.PB(k);

    bool flag = 1;
    for(int i=0; i<n && flag; i++){
        if(op1[i] > op2[i]) flag = 0;
        if(op1[i] < op2[i]) break;
    }
    if(flag){
        for(int k: op1) cout << k << " ";
    }
    else{
        for(int k: op2) cout << k << " ";
    }
    cout << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
