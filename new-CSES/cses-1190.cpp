// 08/05/23 //
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

//const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;

struct Node{
    ll sum=0LL, prefix=0LL, suffix=0LL, max_sub=0LL;

    Node(){}
    Node(ll sum_, ll prefix_, ll suffix_, ll max_sub_){
        sum = sum_;
        prefix = prefix_;
        suffix = suffix_;
        max_sub = max_sub_;
    }

    Node operator+(const Node t){
        ll sum_ = sum + t.sum;

        ll prefix_ = max(prefix, sum+t.prefix);

        ll suffix_ = max(t.suffix, t.sum+suffix);

        ll max_sub_ = max(max(max_sub, t.max_sub), suffix+t.prefix);

        return Node(sum_, prefix_, suffix_, max_sub_);
    }
};

int n, v[MAXN];
Node seg[3*MAXN];

void build(int node, int i, int j){
    if(i==j){
        int aux = max(0, v[i]);
        seg[node] = Node(v[i], aux, aux, aux);
        return;
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    build(l, i, mid);
    build(r, mid+1, j);

    seg[node] = seg[l] + seg[r];
}
/*
Node query(int node, int i, int j, int a, int b){
    if(j < a || b < i){
        return Node(0, -INF, -INF, -INF);
    }
    if(a<=i && j<=b){
        return seg[node];
    }
    
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    return  query(l, i, mid, a, b) + query(r, mid+1, j, a, b);
}
*/

void update(int node, int i, int j, int k, int x){
    if(i==j){
        int aux = max(0, x);
        seg[node] = Node(x, aux, aux, aux);
        return;
    }
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    if(k<=mid) update(l,     i, mid, k, x);
    else       update(r, mid+1,   j, k, x);

    seg[node] = seg[l] + seg[r];
}

int main(){
    fast_io;
    
    int m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> v[i];
    build(1, 1, n);

    while(m--){
        int k, x;
        cin >> k >> x;

        update(1, 1, n, k, x);
        cout << seg[1].max_sub << endl;
    }
    
    return 0;
}