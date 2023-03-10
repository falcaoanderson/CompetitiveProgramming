// 16/07/19 // 7:55 PM //

#include <iostream>

using namespace std;

#define MAXN 100010

int n, q;
int tree[3*MAXN];
int lazy[3*MAXN];
int box[MAXN];

void build(int no, int i, int j){
    if(i==j){
        tree[no] = box[i];
    }
    else{
        int mid   = (i+j)/2;
        int left  = 2*no;
        int right = 2*no+1;

        build( left,     i, mid);
        build(right, mid+1,   j);

        tree[no] = tree[left] + tree[right];
    }
}

void update(int no, int i, int j, int a, int b, int new_value){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]){
        tree[no] = (j-i+1)*lazy[no];

        if(i!=j){
            lazy[left]  = lazy[no];
            lazy[right] = lazy[no];
        }

        lazy[no] = 0;
    }

    if(i>j || b<i || j<a)
        return;
    else if(a<=i && j<=b){
        tree[no] = (j-i+1)*new_value;

        if(i!=j){
            lazy[left]  = new_value;
            lazy[right] = new_value;
        }
    }
    else{
        update( left,     i, mid, a, b, new_value);
        update(right, mid+1,   j, a, b, new_value);

        tree[no] = tree[right] + tree[left];
    }
}

int query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]){
        tree[no] = (j-i+1)*lazy[no];

        if(i!=j){
            lazy[left]  = lazy[no];
            lazy[right] = lazy[no];
        }

        lazy[no] = 0;
    }

    if(i>j || b<i || j<a)
        return 0;

    if(a<=i && j<=b){
        return tree[no];
    }
    else{
        int op_left  = query( left,     i, mid, a, b);
        int op_right = query(right, mid+1,   j, a, b);

        return (op_left + op_right);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++)
        cin >> box[i];

    build(1, 1, n);

    for(int i=1; i<=q; i++){
        int op, a, b, k;
        cin >> op;

        if(op==1){
            cin >> a >> b >> k;

            update(1, 1, n, a, b, k);
        }
        else{
            cin >> a >> b;

            cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}
