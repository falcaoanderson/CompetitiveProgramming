// 13/05/23 // segment tree with lazy propagation
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

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;

struct Lazy{
    ll m=0LL, n=0LL;

    Lazy(){}
    
    Lazy(ll m_, ll n_){
        m = m_;
        n = n_;
    }
};

int n, v[MAXN];
ll seg[3*MAXN];
Lazy lazy[3*MAXN];

void build(int node, int i, int j){
    if(i==j){
        seg[node] = v[i];
        return;
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    build(l, i, mid);
    build(r, mid+1, j);

    seg[node] = seg[l] + seg[r];
}

void push(int node, int i, int j){
    if(lazy[node].m == 0) return;

    seg[node] += ( (lazy[node].m + lazy[node].n) * (ll)(j-i+1) )/2LL;

    if(i!=j){
        int l=2*node, r=2*node+1;

        lazy[l].m += lazy[node].m;
        lazy[l].n += lazy[node].m + ((lazy[node].n-lazy[node].m)/(ll)(j-i)) * (ll)((j-i+2)/2 - 1);

        lazy[r].m += lazy[node].m + ((lazy[node].n-lazy[node].m)/(ll)(j-i)) * (ll)((j-i+2)/2);
        lazy[r].n += lazy[node].n;
    }

    lazy[node] = Lazy(0, 0);
}

void update(int node, int i, int j, int a, int b){
    push(node, i, j);

    if(b < i || j < a) return;

    if(a <= i && j <= b){
        lazy[node] = Lazy(i-a+1, j-a+1);
        push(node, i, j);
        return;
    }
    
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    update(l,     i, mid, a, b);
    update(r, mid+1,   j, a, b);

    seg[node] = seg[l] + seg[r];
}

ll query(int node, int i, int j, int a, int b){
    push(node, i , j);

    if(b < i || j < a) return 0LL;

    if(a <= i && j <= b) return seg[node];
    
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    return query(l, i, mid, a, b) + query(r, mid+1, j, a, b);
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> v[i];    

    build(1, 1, n);

    while(q--){
        int op, a, b;
        cin >> op >> a >> b;

        if(op==1){
            update(1, 1, n, a, b);
        }
        else{
            cout << query(1, 1, n, a, b) << endl;            
        }
    }

    return 0;
}
