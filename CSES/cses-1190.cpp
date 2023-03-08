// 18/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 10;

struct node{
    ll prefix, sufix, sum, maxsub;

    node(){}
    node(ll _prefix, ll _sufix, ll _sum, ll _maxsub){
        prefix = _prefix;
        sufix = _sufix;
        sum = _sum;
        maxsub = _maxsub;
    }

    node operator+(const node& temp){
    
        return node(max(prefix, sum+temp.prefix),
                 max(temp.sufix, sufix+temp.sum),
                                    sum+temp.sum,
                                    max(sufix+temp.prefix, max(maxsub, temp.maxsub)));
    }
};

int n, q; 
ll v[MAXN];
node seg[3*MAXN];

void build(int no, int i, int j){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(i==j){
        seg[no] = node(v[i], v[i], v[i], max(0LL, v[i]));
    }
    else{
        build(l, i, mid);
        build(r, mid+1, j);

        seg[no] = (seg[l] + seg[r]);
    }
}

void update(int no, int i, int j, int pos, ll k){
    int l=2*no, r=2*no+1, mid=(i+j)/2;
    
    if(i==j){
        seg[no] = node(k, k, k, max(0LL, k));
    }
    else{
        if(pos<=mid) update(l, i, mid, pos, k);
        else         update(r, mid+1, j, pos, k);

        seg[no] = (seg[l] + seg[r]);
    }
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];
    
    build(1, 1, n);

    while(q--){
        int pos; ll val;
        cin >> pos >> val;

        update(1, 1, n, pos, val);

        cout << seg[1].maxsub << endl;
    }

    return 0;
}
