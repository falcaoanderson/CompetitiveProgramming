// 10/05/23 // terminar depois
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

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;

struct Node{
    int n, cleft, cright;

    Node(){}
    Node(int n_, int cleft_, int cright_){
        n = n_;
        cleft = cleft_;
        cright = cright_;
    }

    Node operator+(const Node &t){
        int n_, cleft_, cright_;

        n_ = n + t.n;

        cleft_ = min(cleft, t.cleft + n);

        cright_ = min(t.cright, cright + t.n);

        return Node(n_, cleft_, cright_);
    }
};

int n, v[MAXN];
Node seg[3*MAXN];

void build(int node, int i, int j){
    if(i==j){
        seg[node] = Node(1, v[i], v[i]);
        return;
    }
    
    int left = 2*node, right = 2*node+1, mid = (i+j)/2;

    build(left, i, mid);
    build(right, mid+1, j);

    seg[node] = seg[left] + seg[right];
}

void update(int node, int i, int j, int k, int u){
    if(i==j){
        v[i] = u;
        seg[node] = Node(1, v[i], v[i]);
        return;
    }
    
    int left = 2*node, right = 2*node+1, mid = (i+j)/2;
    
    if(k<=mid) update(left, i, mid, k, u);
    else       update(right, mid+1, j, k, u);

    seg[node] = seg[left] + seg[right];
}

Node query(int node, int i, int j, int a, int b){
    if(a<=i && j<=b){
        return seg[node];
    }
    if(j < a || b < i){
        return Node(0, INF, INF);
    }
    
    int left = 2*node, right = 2*node+1, mid = (i+j)/2;
    
    return query(left, i, mid, a, b) + query(right, mid+1, j, a, b);
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> v[i];

    build(1, 1, n);

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int k, x;
            cin >> k >> x;

            update(1, 1, n, k, x);
        }
        else{
            int k;
            cin >> k;
            
            int op1 = v[k];
            int op2 = query(1, 1, n, 1, k-1).cright + 1;
            int op3 = query(1, 1, n, k+1, n).cleft + 1;

            cout << min(op1, min(op2, op3)) << endl;
        }
    }

    return 0;
}
