// 07/05/23 //
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

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;

struct Node{
    ll sum=0LL, prefix=0LL;

    Node(){}
    Node(ll sum_, ll prefix_){
        sum = sum_;
        prefix = prefix_;
    }

    Node operator+(const Node t){
        return Node(sum+t.sum, max(prefix, sum+t.prefix));
    }
};

int n, v[MAXN];
Node seg[3*MAXN];

void build(int node, int i, int j){
    if(i==j){
        seg[node] = Node(v[i], max(0, v[i]));
        //cout << " (" << i << ", " << j << ") -> " << " (" << seg[node].sum << ", " << seg[node].prefix << ")" << endl;
        return;
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    build(l, i, mid);
    build(r, mid+1, j);

    seg[node] = seg[l] + seg[r];
}

void update(int node, int i, int j, int k, int u){
    if(i==j){
        seg[node] = Node(u, max(0, u));
        return;
    }
    
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    if(k<=mid) update(l, i, mid, k, u);
    else       update(r, mid+1, j, k, u);
    
    seg[node] = seg[l] + seg[r];
}

Node query(int node, int i, int j, int a, int b){
    if(j < a || b < i){
        return Node(0, -INF);
    }
    if(a<=i && j<=b){
        return seg[node];
    }
    
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    return  query(l, i, mid, a, b) + query(r, mid+1, j, a, b);
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

        if(op==1){ //update
            update(1, 1, n, a, b);
        }
        else{ //query
            cout << query(1, 1, n, a, b).prefix << endl;
        }
    }

    return 0;
}