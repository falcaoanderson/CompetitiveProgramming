// 29/08/19 // 11:26 AM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define ll long long

int t, n, c;
ll seg[3*MAXN], lazy[3*MAXN];

void push(int no, int i, int j){
    int left  = 2*no;
    int right = 2*no+1;

    seg[no] += (j-i+1)*lazy[no];

    if(i!=j){
        lazy[left]  += lazy[no];
        lazy[right] += lazy[no];
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int a, int b, ll sum){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return;
    }
    else if(a<=i && j<=b){
        lazy[no] += sum;
        push(no, i, j);
    }
    else{
        update( left,     i, mid, a, b, sum);
        update(right, mid+1,   j, a, b, sum);

        seg[no] = seg[left] + seg[right];
    }
}

ll query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return -1;
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        ll op_left  = query( left,     i, mid, a, b);
        ll op_right = query(right, mid+1,   j, a, b);

        if(op_left ==-1) return op_right;
        if(op_right==-1) return op_left;

        return (op_right+op_left);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n >> c;

        memset(lazy, 0, sizeof(lazy));
        memset( seg, 0, sizeof( seg));

        for(int i=0; i<c; i++){
            int op, a, b;
            ll sum;

            cin >> op >> a >> b;

            if(op==0){
                cin >> sum;
                update(1, 1, n, a, b, sum);
            }
            else{
                cout << query(1, 1, n, a, b) << "\n";
            }
        }
    }


    return 0;
}
