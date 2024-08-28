/*
28/08/24 
Problem: 
Complexity: O(n + q*log^2(n) )
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

struct Node{
    bool flag = 0;
    ll sum = 0LL, minprefix = 0LL;

    Node(){}
    Node(bool flag_, ll sum_, ll minprefix_){
        flag = flag_;
        sum  = sum_;
        minprefix = minprefix_;
    }

    Node operator+(const Node &oth){
        return Node(flag && (sum+oth.minprefix>=0LL), 
                     sum+oth.sum,
                     min(minprefix, sum+oth.minprefix));
    }
};

Node seg[4*MAXN];
int n, b[MAXN], c[MAXN], v[MAXN];

void build(int node, int i, int j){
    if(i==j){
        seg[node] = Node(v[i]>=0, v[i], v[i]);
        return;
    }

    build(  2*node,           i, (i+j)/2);
    build(2*node+1, (i+j)/2 + 1,       j);

    seg[node] = seg[2*node] + seg[2*node+1];
}

void update(int node, int i, int j, int idx, ll delta){
    if(i==j){
        v[i] += delta;
        seg[node] = Node(v[i]>=0, v[i], v[i]);
        return;
    }
    if(idx<=(i+j)/2){
        update(2*node, i, (i+j)/2, idx, delta);
    }
    else{
        update(2*node+1, (i+j)/2+1, j, idx, delta);
    }

    seg[node] = seg[2*node] + seg[2*node+1];
}

Node query(int node, int i, int j, int a, int b){
    int l=2*node, r=2*node+1, mid=(i+j)/2;
    
    if(j < a || b < i){
        return Node(1, 0, LINF);
    }
    if(a<=i && j<=b){
        return seg[node];
    }
    
    Node ql = query(l,     i, mid, a, b);
    Node qr = query(r, mid+1,   j, a, b);

    return ql + qr;
}

int main(){
    fast_io;
    
    int q;
    cin >> n >> q;

    for(int i=1; i<=n; i++){
        cin >> b[i];
        b[i+n] = b[i];
    }
    for(int i=1; i<=n; i++){
        cin >> c[i];
        c[i+n] = c[i];

        v[i] = v[i+n] = b[i]-c[i];
    }

    build(1, 1, 2*n);

    while(q--){
        int op, ind;
        cin >> op >> ind;

        if(op==1){ // query
            if(v[ind]<0){
                cout << ind << endl;
                continue;
            }

            int l=ind, r=2*n, resp=0;
            while(l<=r){
                int mid = (l+r)/2;

                if(query(1, 1, 2*n, ind, mid).flag){
                    resp = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            cout << (resp==2*n? -1 : (resp)%n+1) << endl;
        }
        else if(op==2){ // update
            int x;
            cin >> x;
            
            update(1, 1, 2*n, ind, x-b[ind]);
            update(1, 1, 2*n, ind+n, x-b[ind]);
            b[ind] = b[ind+n]= x;
        }
        else{
            int x;
            cin >> x;
            
            update(1, 1, 2*n, ind, c[ind]-x);
            update(1, 1, 2*n, ind+n, c[ind]-x);
            c[ind] = c[ind+n] = x;
        }
    }

    return 0;
}