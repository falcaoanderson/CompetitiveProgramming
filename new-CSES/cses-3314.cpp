/*
27/08/25 

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
const int LOGMAXN = 17 + 5;
const int MOD  = (1e9) + 7;

int tb_r[MAXN][LOGMAXN], tb_l[MAXN][LOGMAXN];
int seg[4*MAXN];

void update(int node, int i, int j, int idx, int val){
    if(i==j){
        seg[node] = val;
        return;
    }
    int mid = (i+j)/2;
    if(idx<=mid) update(2*node+1, i, mid, idx, val);
    else         update(2*node+2, mid+1, j, idx, val);
    seg[node] = max(seg[2*node+1], seg[2*node+2]);
}
int query(int node, int i, int j, int a, int b){
    if(a<=i && j<=b){
        return seg[node];
    }
    if(b<i || j<a){
        return -INF;
    }
    return max(query(2*node+1, i, (i+j)/2, a, b), query(2*node+2, (i+j)/2+1, j, a, b));
}

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n);
    vector<pii> idx(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
        idx[i] = {v[i], i};
    }
    sort(idx.begin(), idx.end());

    for(int i=0; i<n; i++){
        tb_l[i][0] = tb_r[i][0] = i;
    }
    for(int k=1; (1<<k)<=n; k++){
        for(int i=(1<<k)-1; i<n; i++){
            int& op1=tb_l[i][k-1], op2=tb_l[i-(1<<(k-1))][k-1]; 
            if(v[op1] > v[op2]){
                tb_l[i][k] = op1;
            }
            else{
                tb_l[i][k] = op2;
            }
        }
        for(int i=0; i+(1<<k)-1<n; i++){
            int& op1=tb_r[i][k-1], op2=tb_r[i+(1<<(k-1))][k-1]; 
            if(v[op1] > v[op2]){
                tb_r[i][k] = op1;
            }
            else{
                tb_r[i][k] = op2;
            }
        }
    }

    int resp=0;
    for(pii p: idx){
        int i = p.second;
        
        int l=i, r=i; 
        for(int k=17; k>=0; k--){
            int nl = (l-1) -(1<<k)+1; 
            if(nl>=0 && v[tb_l[l-1][k]]<v[i]){
                l = nl;

                
            }
        }
        for(int k=17; k>=0; k--){
            int nr = (r+1) +(1<<k)-1; 
            if(nr<n && v[tb_r[r+1][k]]<v[i]){
                r = nr;
            }
        }

        int crr_resp = query(0, 0, n-1, l, r) + 1;
        update(0, 0, n-1, i, crr_resp);

        resp = max(resp, crr_resp);
    }

    cout << resp << endl;

    return 0;
}
