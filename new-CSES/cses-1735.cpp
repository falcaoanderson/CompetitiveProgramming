// 12/05/23 // segment tree with lazy propagation
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
    ll sum=0LL, setx=-1;

    Lazy(){}

    Lazy(ll sum_, ll setx_){
        sum = sum_;
        setx = setx_;
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
    if(lazy[node].sum==0 && lazy[node].setx == -1) return; //nada para alterar

    if(lazy[node].setx!=-1) // seta valor na seg
        seg[node] = ((ll)(j-i+1)) * lazy[node].setx;
    
    seg[node] += ((ll)(j-i+1)) * lazy[node].sum; //incrementa valor na seg    
    
    if(i!=j){
        int l=2*node, r=2*node+1;

        if(lazy[node].setx!=-1){
            lazy[l] = lazy[node];
            lazy[r] = lazy[node];
        }
        else{
            lazy[l].sum += lazy[node].sum;
            lazy[r].sum += lazy[node].sum;
        }
    }

    lazy[node] = Lazy(0, -1);
}

void update(int node, int i, int j, int a, int b, int x, int op){
    push(node, i, j);
    
    if(b < i || j < a) return;
    
    if(a<=i && j <=b){
        if(op==1) lazy[node] = Lazy(x, -1);
        if(op==2) lazy[node] = Lazy(0, x);

        push(node, i, j);

        return;    
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    update(l,     i, mid, a, b, x, op);
    update(r, mid+1,   j, a, b, x, op);

    seg[node] = seg[l] + seg[r];
}

ll query(int node, int i, int j, int a, int b){
    if(b < i || j < a) return 0LL;

    push(node, i, j);
    
    if(a<=i && j <=b){
        return seg[node];
    }

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
        int op, a, b, x;
        cin >> op >> a >> b;

        if(op==3){
            cout << query(1, 1, n, a, b) << endl;
        }
        else{
            cin >> x;

            update(1, 1, n, a, b, x, op);
        }
    }

    return 0;
}