// 30/05/20 // 6:31 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = (int)(2e5) + 10;

int n, q;
int v[MAXN], seg[3*MAXN];

void build(int no, int i, int j){
    int mid=(i+j)/2, left=2*no, right=2*no+1;

    if(i==j){
        seg[no] = v[i];
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        seg[no] = seg[left] + seg[right];
    }
}

void update(int no, int i, int j, int k, int u){
    int mid=(i+j)/2, left=2*no, right=2*no+1;

    if(i==j){
        v[k]    = u;
        seg[no] = u;
    }
    else{
        if(k<=mid) update( left,     i, mid, k, u);
        else       update(right, mid+1,   j, k, u);

        seg[no] = seg[left] + seg[right];
    }
}
int query(int no, int i, int j, int a, int b){
    int mid=(i+j)/2, left=2*no, right=2*no+1;

    if(a<=i && j<=b){
        return seg[no];
    }
    else if(j<a || b<i){
        return 0;
    }
    else{
        int op_left  = query( left,     i, mid, a, b);
        int op_right = query(right, mid+1,   j, a, b);

        return (op_left+op_right);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> v[i];
    build(1, 1, n);

    while(q--){
        int q, a, b;
        cin >> q >> a >> b;

        if(q==1){
            update(1, 1, n, a, b);
        }
        else{
            cout << query(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
