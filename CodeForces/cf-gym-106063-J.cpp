// 06/09/25

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'

const int MAXN = 1e6 + 5;
int n, q;
ll v[MAXN], seg[4*MAXN];

void build(int node, int i, int j){
    if(i==j){
        seg[node] = v[i];
        return;
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    build(l, i, mid);
    build(r, mid+1, j);

    seg[node] = (seg[l] ^ seg[r]);
}

ll query(int node, int i, int j, int a, int b){
    if(a<=i && j<=b){
        return seg[node];
    } 
    if(j<a || b<i){
        return 0;
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    return query(l, i, mid, a, b)^query(r, mid+1, j, a, b);
}

void update(int node, int i, int j, int k, ll x){
    if(i==j){
        v[k] += x;
        seg[node] = v[k];
        return;
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;
    if(k<=mid){
        update(l, i, mid, k, x);
    }
    else{
        update(r, mid+1, j, k, x);
    }

    seg[node] = (seg[l]^seg[r]);
}

int main() {
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];

    build(1, 1, n);

    while(q--){
        char op;
        cin >> op;

        if(op=='P'){
            int l, r;
            cin >> l >> r;

            cout << (query(1, 1, n, l, r)!=0LL?"FRANK":"JUAN") << endl;
        }
        else{
            int k;
            ll x;
            cin >> k >> x;

            update(1, 1, n, k, x);
        }
    }

    return 0;
}