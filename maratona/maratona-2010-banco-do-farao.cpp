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
const int MAXN = (1e5) + 5;

struct Node{
    ll sum=0LL, prefix=0LL, suffix=0LL, max_sub=0LL;
    int n_total=1, n_prefix=1, n_suffix=1, n_max_sub=1;

    Node(){}
    Node(ll sum_, ll prefix_, ll suffix_, ll max_sub_, int n_total_=1, int n_prefix_=1, int n_suffix_=1, int n_max_sub_=1){
        sum = sum_;
        prefix = prefix_;
        suffix = suffix_;
        max_sub = max_sub_;

        n_total = n_total_;
        n_prefix = n_prefix_;
        n_suffix = n_suffix_;
        n_max_sub = n_max_sub_;
    }

    Node operator+(const Node t){
        ll sum_, prefix_, suffix_, max_sub_;
        int n_total_ = 1, n_prefix_ = 1, n_suffix_ = 1, n_max_sub_ = 1;

        // sum
        sum_ = sum + t.sum;
        n_total_ = n_total + t.n_total;
        
        //prefix
        if(sum+t.prefix>=prefix){
            prefix_ = sum+t.prefix;
            n_prefix_ = n_total + t.n_prefix;
        }
        else{
            prefix_ = prefix;
            n_prefix_ = n_prefix;
        }

        //suffix
        if(t.sum+suffix >= t.suffix){
            suffix_ = t.sum+suffix;
            n_suffix_ = t.n_total + n_suffix;
        }
        else{
            suffix_ = t.suffix;
            n_suffix_ = t.n_suffix;
        }

        //max_sub
        if(max_sub > t.max_sub || (max_sub==t.max_sub && n_max_sub>=t.n_max_sub)){
            max_sub_ = max_sub;
            n_max_sub_ = n_max_sub;
        }
        else{
            max_sub_ = t.max_sub;
            n_max_sub_ = t.n_max_sub;
        }

        if(suffix+t.prefix > max_sub_ || (suffix+t.prefix == max_sub_ && n_suffix+t.n_prefix>n_max_sub_)){
            max_sub_ = suffix+t.prefix;
            n_max_sub_ = n_suffix+t.n_prefix;
        }

        return Node(sum_, prefix_, suffix_, max_sub_, n_total_, n_prefix_, n_suffix_, n_max_sub_);
    }
};

int n, v[MAXN];
Node seg[3*MAXN];

void build(int node, int i, int j){
    if(i==j){
        seg[node] = Node(v[i], v[i], v[i], v[i]);
        return;
    }

    int l=2*node, r=2*node+1, mid=(i+j)/2;

    build(l, i, mid);
    build(r, mid+1, j);

    seg[node] = seg[l] + seg[r];
}

Node query(int node, int i, int j, int a, int b){
    if(j < a || b < i){
        return Node(0, -INF, -INF, -INF, 0, 0, 0, 0);
    }
    if(a<=i && j<=b){
        return seg[node];
    }
    
    int l=2*node, r=2*node+1, mid=(i+j)/2;

    return  query(l, i, mid, a, b) + query(r, mid+1, j, a, b);
}

int main(){
    fast_io;
    
    int t;
    cin >> t;

    while(t--){
        cin >> n;

        for(int i=1; i<=n; i++) cin >> v[i];
        build(1, 1, n);
        
        int q;
        cin >> q;

        while(q--){
            int a, b;
            cin >> a >> b;

            Node resp = query(1, 1, n, a, b);
            cout << resp.max_sub << " " << resp.n_max_sub << endl;
        }
    }

    return 0;
}