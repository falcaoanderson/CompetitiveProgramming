// 30/08/19 // 7:25 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

struct seg_node{
    int sum=0, treze=0, sete=0;

    seg_node(){};
    seg_node(int _sum, int _treze, int _sete){
        sum   = _sum;
        treze = _treze;
        sete  = _sete;
    }

    seg_node operator+(const seg_node &temp){
        return seg_node(sum + temp.sum, treze + temp.treze, sete + temp.sete);
    }

};
struct lazy_node{
    int new_treze=-1, new_sete=-1;

    lazy_node(){};
    lazy_node(int _new_treze, int _new_sete){
        new_treze = _new_treze;
        new_sete  = _new_sete;
    }

    lazy_node operator+(const lazy_node &temp){
        return lazy_node(temp.new_treze, temp.new_sete);
    }
};

int n, q;
int value[MAXN];
seg_node  seg[3*MAXN];
lazy_node lazy[3*MAXN];

void build(int no, int i, int j){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    lazy[no] = lazy_node(0,0);

    if(i==j){
        seg[no] = seg_node(0,0,0);

        if(value[i] == 7)
            seg[no].sete++;
        else if(value[i] == 13)
            seg[no].treze++;
        else
            seg[no].sum += value[i];
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        seg[no] = seg[left] + seg[right];
    }
}

void push(int no, int i, int j){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no].new_sete>=0){
        if(lazy[no].new_sete == 13)
            seg[no].treze += seg[no].sete;
        else
            seg[no].sum += seg[no].sete * lazy[no].new_sete;

        seg[no].sete = 0;
    }
    if(lazy[no].new_treze >= 0){
        if(lazy[no].new_treze == 7)
            seg[no].sete += seg[no].treze;
        else
            seg[no].sum += seg[no].treze * lazy[no].new_treze;

        seg[no].treze = 0;
    }

    if(i!=j){
        if(lazy[left].new_sete==13  || lazy[left].new_treze==7)  push(left, i, mid);
        if(lazy[right].new_sete==13 || lazy[right].new_treze==7) push(right, mid+1, j);

        lazy[left]  = lazy[left]  + lazy[no];
        lazy[right] = lazy[right] + lazy[no];
    }

    lazy[no] = lazy_node(0,0);
}

void update_range(int no, int i, int j, int a, int b, int num, int new_num){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no].new_sete>=0 || lazy[no].new_treze>=0) push(no, i, j);

    if(i>j || a>b || b<i || j<a)
        return;
    else if(a<=i && j<=b){
        if(num==7){
            lazy[no].new_sete = new_num;
        }
        else if(num==13){
            lazy[no].new_treze = new_num;
        }

        push(no, i, j);
    }
    else{
        update_range( left,     i, mid, a, b, num, new_num);
        update_range(right, mid+1,   j, a, b, num, new_num);

        seg[no] = seg[left] + seg[right];
    }

}

void update_one(int no, int i, int j, int ind, int new_value){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no].new_sete>=0 || lazy[no].new_treze>=0) push(no, i, j);

    if(i==j){
        seg[no] = seg_node(0,0,0);

        if(new_value==7)
            seg[no].sete=1;
        else if(new_value==13)
            seg[no].treze=1;
        else
            seg[no].sum = new_value;
    }
    else{
        if(ind<=mid){
            update_one( left,     i, mid, ind, new_value);
            if(lazy[right].new_sete>=0 || lazy[right].new_treze>=0) push(right, mid+1, j);
        }
        else{
            update_one(right, mid+1,   j, ind, new_value);
            if(lazy[left].new_sete>=0 || lazy[left].new_treze>=0) push(left, i, mid);
        }

        seg[no] = seg[left] + seg[right];
    }
}

int query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no].new_sete>=0 || lazy[no].new_treze>=0) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return 0;
    }
    else if(a<=i && j<=b){
        return (seg[no].sum + seg[no].sete*7 + seg[no].treze*13);
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

    while(cin >> n){
        if(n==0) break;

        for(int i=1; i<=n; i++)
            cin >> value[i];

        build(1, 1, n);

        cin >> q;

        while(q--){
            int op, i, j, z, v;

            cin >> op >> i >> j;

            if(op==1){
                update_one(1, 1, n, i, j);
            }
            else if(op==2){
                cin >> z >> v;

                update_range(1, 1, n, i, j, z, v);
            }
            else{
                cout << query(1, 1, n, i, j) << "\n";
            }
        }
    }

    return 0;
}
