// 19/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

const int MAXN = (2e5) + 10;

int n, q;
ll v[MAXN], seg[3*MAXN], lazy[3*MAXN];
int op_lazy[3*MAXN]; 

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

void push1(int no, int i, int j){ // aumentar
    int l=2*no, r=2*no+1;

    seg[no] += (ll)(j-i+1) * lazy[no];

    if(i!=j){
        lazy[l] += lazy[no];
        lazy[r] += lazy[no];

        if(op_lazy[l]==2) op_lazy[l] = 2;
        else              op_lazy[l] = 1;

        if(op_lazy[r]==2) op_lazy[r] = 2;
        else              op_lazy[r] = 1;
    }   

    lazy[no] = 0LL; op_lazy[no] = 0;
}
void push2(int no, int i, int j){ // setar
    int l=2*no, r=2*no+1;

    seg[no] = (ll)(j-i+1) * lazy[no];
    
    if(i!=j){
        lazy[l] = lazy[no];
        lazy[r] = lazy[no];

        op_lazy[l] = 2;
        op_lazy[r] = 2;
    } 

    lazy[no] = 0LL; op_lazy[no] = 0;
}

void update(int no, int i, int j, int a, int b, ll val, int op){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(op_lazy[no]==1) push1(no, i, j);
    if(op_lazy[no]==2) push2(no, i, j);

    if(j<a || b<i) return;

    if(a<=i && j<=b){
        lazy[no] = val;
        op_lazy[no] = op;
        
        if(op_lazy[no]==1) push1(no, i, j);
        if(op_lazy[no]==2) push2(no, i, j);
    }
    else{
        update(l, i, mid, a, b, val, op);
        update(r, mid+1, j, a, b, val, op);

        seg[no] = seg[l] + seg[r];
    }
}

ll query(int no, int i, int j, int a, int b){
    int l=2*no, r=2*no+1, mid=(i+j)/2;

    if(op_lazy[no]==1) push1(no, i, j);
    if(op_lazy[no]==2) push2(no, i, j);

    if(j<a || b<i) 
        return 0LL;
    if(a<=i && j<=b)
        return seg[no];
    
    ll opl = query(l, i, mid, a, b);
    ll opr = query(r, mid+1, j, a, b);

    return opl+opr;
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];

    build();

    while(q--){
        int op;
        cin >> op;

        if(op==1){ // aumentar
            int a, b; ll val;
            cin >> a >> b >> val;

            update(1, 1, n, a, b, val, 1);
        }
        if(op==2){ // setar
            int a, b; ll val;
            cin >> a >> b >> val;

            update(1, 1, n, a, b, val, 2);
        }
        if(op==3){ // soma
            int a, b;
            cin >> a >> b;

            cout << query(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}