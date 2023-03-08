// 14/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int n, q;
int v[MAXN], seg[3*MAXN];

void build(int no, int i, int j){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(i==j){
        seg[no] = v[i];
    }
    else{
        build(l, i, mid);
        build(r, mid+1, j);

        seg[no] = min(seg[l], seg[r]);
    }
}

int query(int no, int i, int j, int a, int b){
    int l=2*no, r=2*no+1, mid=(i+j)/2;
    
    if(b<i || j<a){
        return INF;
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        int op_l = query(l, i, mid, a, b);
        int op_r = query(r, mid+1, j, a, b);

        return min(op_l, op_r);
    }
}

void update(int no, int i, int j, int pos, int val){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(i==j){
        seg[no] = val;
    }
    else{
        if(pos<=mid)
            update(l, i, mid, pos, val);
        else
            update(r, mid+1, j, pos, val);
        
        seg[no] = min(seg[l], seg[r]);
    }
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++) 
        cin >> v[i];
    
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
