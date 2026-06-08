/*
24/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;

struct Node{
    int sum = 0, min_prefix = 0;
    
    Node(){};

    Node operator+ (const Node& oth){
        Node temp;
        temp.sum = sum + oth.sum;
        temp.min_prefix = min(min_prefix, sum + oth.min_prefix);
        return temp;
    }
};

int v[MAXN];
Node seg[4 * MAXN];

void build(int node, int l, int r){
    if(l==r){
        seg[node].sum = v[l];
        seg[node].min_prefix = min(0, v[l]);
        return;
    }
    
    int mid = (l+r) / 2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    seg[node] = seg[2*node] + seg[2*node+1];
}

void update(int node, int l, int r, int pos){
    if(l==r){
        v[l] = (v[l]==1? -1: 1);   
        seg[node].sum = v[l];
        seg[node].min_prefix = min(0, v[l]);
        return;
    }

    int mid = (l+r) / 2;

    if(pos <= mid){
        update(2*node, l, mid, pos);
    }
    else{
        update(2*node+1, mid+1, r, pos);
    }

    seg[node] = seg[2*node] + seg[2*node+1];
}

void solve(int ii){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        char c;
        cin >> c;

        v[i] = (c=='('? 1: -1);
    }

    build(1, 1, n);

    int q;
    cin >> q;

    cout << "Test " << ii << ":" << endl;
    
    while(q--){
        int idx;
        cin >> idx;

        if(idx==0){
            cout << (seg[1].sum == 0 && seg[1].min_prefix >= 0? "YES": "NO") << endl;
        }
        else{
            update(1, 1, n, idx);
        }
    }
    //cout << endl;
}

int main(){
    fast_io;

    for(int i=1; i<=10; i++){
        solve(i);
    } 

    return 0;
}