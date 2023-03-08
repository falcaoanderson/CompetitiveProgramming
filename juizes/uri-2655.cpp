// 29/08/19 // 5:29 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define ll long long

int n, q, m;
int type[MAXN];
ll seg[3*MAXN];

void build(int no, int i, int j){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(i==j){
        seg[no] = (1LL<<(type[i]));
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        seg[no] = (seg[left]|seg[right]);
    }
}

void update(int no, int i, int j, int ind, int new_type){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(i==j){
        type[i] = new_type;
        seg[no] = (1LL<<new_type);
    }
    else{
        if(ind<=mid) update(left,      i, mid, ind, new_type);
        else         update(right, mid+1,   j, ind, new_type);

        seg[no] = (seg[left]|seg[right]);
    }
}

ll query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(i>j || a>b || b<i || j<a)
        return 0LL;
    else if(a<=i && j<=b)
        return seg[no];
    else{
        ll op_left  = query( left,     i, mid, a, b);
        ll op_right = query(right, mid+1,   j, a, b);

        return (op_left|op_right);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q >> m;

    for(int i=1; i<=n; i++)
        cin >> type[i];

    build(1, 1, n);

    while(q--){
        int op, a, b;

        cin >> op >> a >> b;

        if(op==1){
            ll temp = query(1, 1, n, a, b);
            int resp = 0;

            while(temp){
                resp++;
                temp ^= (temp&(-temp));
            }

            cout << resp << "\n";
        }
        else{
            update(1, 1, n, a, b);
        }
    }

    return 0;
}
