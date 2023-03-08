// 10/09/19 // 9:56 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MLR int mid=(i+j)/2, left=2*no, right=2*no+1

int n, q;
int v[MAXN], seg[3*MAXN];

void build(int no, int i, int j){
    MLR;

    if(i==j){
        seg[no] = v[i];
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        seg[no] = seg[left] + seg[right];
    }
}

void update(int no, int i, int j, int ind, int new_value){
    MLR;

    if(i==j){
        seg[no] = new_value;
    }
    else{
        if(ind<=mid)
            update( left,     i, mid, ind, new_value);
        else
            update(right, mid+1,   j, ind, new_value);

        seg[no] = seg[left] + seg[right];
    }
}

int query(int no, int i, int j, int a, int b){
    MLR;

    if(i>j || a>b || b<i || j<a){
        return 0;
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        int opl = query( left,     i, mid, a, b);
        int opr = query(right, mid+1,   j, a, b);

        return (opl+opr);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> v[i];

    build(1, 1, n);

    while(q--){
        int op, a, b;
        cin >> op >> a;

        if(op==0){
            cin >> b;

            update(1, 1, n, a, b);
        }
        else{
            cout << query(1, 1, n, 1, a) << "\n";
        }

    }

    return 0;
}
