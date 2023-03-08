// 19/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

struct nodeLazy{
    ll ini=0LL, rr=0LL;
};

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int n, q;
ll v[MAXN], seg[3*MAXN];
nodeLazy lazy[3*MAXN];

void build(int no=1, int i=1, int j=n){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(i==j){
        seg[no] = v[i];
    }
    else{
        build(l, i, mid);
        build(r, mid+1, j);

        seg[no] = seg[l] + seg[r];
    }
}

void push(int no, int i, int j){
    int l=2*no, r=2*no+1, mid=(i+j)/2;
    
    ll  a=lazy[no].ini, k=lazy[no].rr;
    ll num = j-i+1;

    seg[no] += num*a + (k*num*(num-1))/2;

    if(i!=j){
        lazy[l].rr += k;
        lazy[r].rr += k;

        lazy[l].ini += a;
        lazy[r].ini += a + k*(mid-i+1);
    }

    lazy[no].ini  = lazy[no].rr = 0LL;
}

ll query(int no, int i, int j, int a, int b){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(lazy[no].ini!=0LL) push(no, i, j);

    if(j<a || b<i) return 0LL;

    if(a<=i && j<=b)
        return seg[no];
    
    ll opl = query(l, i, mid, a, b);
    ll opr = query(r, mid+1, j, a, b);

    return opl+opr;
}

void update(int no, int i, int j, int a, int b){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(lazy[no].ini!=0LL) push(no, i, j);

    if(j<a || b<i) return;
    if(a<=i && j<=b){
        lazy[no].ini = i-a+1;
        lazy[no].rr  = 1;

        push(no, i, j);
    }
    else{
        update(l, i, mid, a, b);
        update(r, mid+1, j, a, b);

        seg[no] = seg[l] + seg[r];
    }
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];
    
    build();

    while(q--){
        int op, a, b;
        cin >> op >> a >> b;

        if(op==1)
            update(1, 1, n, a, b);
        else
            cout << query(1, 1, n, a, b) << endl;
    }

    return 0;
}
