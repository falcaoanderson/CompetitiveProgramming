// 29/08/19 // 2:31 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

struct node{
    int v=0;
    int ind;

    node(){}
    node(int _v, int _ind){
        v   = _v;
        ind = _ind;
    }
};

int n, q;
int value[MAXN], lazy[3*MAXN];
node seg[3*MAXN];

void build(int no, int i, int j){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;
    lazy[no] = 0;

    if(i==j){
        seg[no].v = value[i];
        seg[no].ind = i;
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        if(seg[left].v >= seg[right].v){
            seg[no].v   = seg[left].v;
            seg[no].ind = seg[left].ind;
        }
        else{
            seg[no].v   = seg[right].v;
            seg[no].ind = seg[right].ind;
        }
    }
}

void push(int no, int i, int j){
    int left  = 2*no;
    int right = 2*no+1;

    seg[no].v += lazy[no];

    if(i!=j){
        lazy[left]  += lazy[no];
        lazy[right] += lazy[no];
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int a, int b, int sum){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return;
    }
    else if(a<=i && j<=b){
        lazy[no]+=sum;

        push(no, i, j);
    }
    else{
        update( left,     i, mid, a, b, sum);
        update(right, mid+1,   j, a, b, sum);

        if(seg[left].v >= seg[right].v){
            seg[no].v   = seg[left].v;
            seg[no].ind = seg[left].ind;
        }
        else{
            seg[no].v   = seg[right].v;
            seg[no].ind = seg[right].ind;
        }
    }

}

node query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return node(-1,-1);
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        node op_left  = query( left,     i, mid, a, b);
        node op_right = query(right, mid+1,   j, a, b);

        if(op_left.v  == -1) return op_right;
        if(op_right.v == -1) return op_left;

        if(op_left.v >= op_right.v){
            return op_left;
        }
        else{
            return op_right;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> q){
        //if(n==0) break;

        for(int i=1; i<=n; i++) cin >> value[i];

        build(1, 1, n);

        while(q--){
            char op;
            int a, b, sum;
            node temp;

            cin >> op >> a >> b;

            if(op=='A'){
                cin >> sum;
                update(1, 1, n, a, b, sum);
            }
            else{
                temp = query(1, 1, n, a, b);
                cout << temp.ind << "\n";
            }
        }

    }

    return 0;
}
