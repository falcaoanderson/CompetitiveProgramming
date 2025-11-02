/*
10/09/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;

struct Node{
    vector<pii> val_freq;

    Node(){
        val_freq.assign(2, {-INF, 0});
    }
    Node(pii fst, pii snd){
        val_freq = {fst, snd};
    }

    Node operator+ (const Node& oth){
        vector<pii> temp=val_freq;

        for(int i=0; i<2; i++){
            if(temp[i].FF==oth.val_freq[0].FF){
                temp[i].SS += oth.val_freq[0].SS;
            }
            else if(temp[i].FF==oth.val_freq[1].FF){
                temp[i].SS += oth.val_freq[1].SS;
            }
        }
        for(int i=0; i<2; i++){
            if(oth.val_freq[i].FF!=temp[0].FF && oth.val_freq[i].FF!=temp[1].FF){
                temp.EB(oth.val_freq[i].FF, oth.val_freq[i].SS);
            }
        }

        sort(temp.rbegin(), temp.rend());
        
        while(SZ(temp)>2) temp.pop_back();
        return Node(temp[0], temp[1]);
    }
}; 

int n, q, v[MAXN];
Node seg[4*MAXN];

void build(int node, int i, int j){
    // cout << "build: " << node << " " << i << " " << j << endl;
    if(i==j){
        seg[node].val_freq[0] = {v[i], 1};
        return;
    }

    int l=2*node,r=2*node+1,mid=(i+j)/2;

    build(l, i, mid);
    build(r, mid+1, j);

    seg[node] = seg[l]+seg[r];
}
Node query(int node, int i, int j, int a, int b){
    // cout << "query: " << node << " " << i << " " << j << endl;
    if(a<=i && j<=b){
        return seg[node];
    }
    if(b<i || j<a){
        return Node();
    }

    int l=2*node,r=2*node+1,mid=(i+j)/2;
    return query(l, i, mid, a, b) + query(r, mid+1, j, a, b);
}
void update(int node, int i, int j, int idx, int val){
    // cout << "update: " << node << " " << i << " " << j << endl;
    if(i==j){
        seg[node].val_freq[0] = {val, 1};
        return;
    }

    int l=2*node,r=2*node+1,mid=(i+j)/2;
    
    if(idx<=mid){
        update(l, i, mid, idx, val);
    }
    else{
        update(r, mid+1, j, idx, val);
    }

    seg[node] = seg[l] + seg[r];
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    build(1, 1, n);

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int idx, newval;
            cin >> idx >> newval;

            update(1, 1, n, idx, newval);
        }
        else{
            int l, r;
            cin >> l >> r;

            cout << query(1, 1, n, l, r).val_freq[1].second << endl;
        }
    }

    return 0;
}
