// 27/08/19 // 11:00 PM //

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 100010
#define maior first
#define menor second

int n, m;
pair<int, int > value[MAXN];
int seg_min[3*MAXN], seg_max[3*MAXN];

void build(int no, int i, int j){
    if(i==j){
        seg_min[no] = i;
        seg_max[no] = i;
    }
    else{
        int mid   = (i+j)/2;
        int left  = 2*no;
        int right = 2*no+1;

        build( left,     i, mid);
        build(right, mid+1,   j);

        if(value[ seg_min[left] ].menor <= value[ seg_min[right] ].menor)
            seg_min[no] = seg_min[left];
        else
            seg_min[no] = seg_min[right];

        if(value[ seg_max[left] ].maior >= value[ seg_max[right] ].maior)
            seg_max[no] = seg_max[left];
        else
            seg_max[no] = seg_max[right];

    }
}

void update(int no, int i, int j, int pos, int new_value){
    if(i==j){
        if(value[i].maior < new_value)
            value[i].maior = new_value;

        if(value[i].menor > new_value)
            value[i].menor = new_value;
    }
    else{
        int mid   = (i+j)/2;
        int left  = 2*no;
        int right = 2*no+1;

        if(pos<=mid)
            update(left, i, mid, pos, new_value);
        else
            update(right, mid+1, j, pos, new_value);


        if(value[ seg_min[left] ].menor <= value[ seg_min[right] ].menor)
            seg_min[no] = seg_min[left];
        else
            seg_min[no] = seg_min[right];

        if(value[ seg_max[left] ].maior >= value[ seg_max[right] ].maior)
            seg_max[no] = seg_max[left];
        else
            seg_max[no] = seg_max[right];
    }
}

int query_min(int no, int i, int j, int a, int b){

    if(i>j || b<i || j<a || a>b)
        return 0;
    else if(a<=i && j<=b){
        return seg_min[no];
    }
    else{
        int mid   = (i+j)/2;
        int left  = 2*no;
        int right = 2*no+1;

        int op_left  = query_min( left,     i, mid, a, b);
        int op_right = query_min(right, mid+1,   j, a, b);

        if(op_left==0)  return op_right;
        if(op_right==0) return op_left;

        if(value[op_left].menor <= value[op_right].menor)
            return op_left;
        else
            return op_right;
    }
}

int query_max(int no, int i, int j, int a, int b){

    if(i>j || b<i || j<a || a>b)
        return 0;
    else if(a<=i && j<=b){
        return seg_max[no];
    }
    else{
        int mid   = (i+j)/2;
        int left  = 2*no;
        int right = 2*no+1;

        int op_left  = query_max( left,     i, mid, a, b);
        int op_right = query_max(right, mid+1,   j, a, b);

        if(op_left==0)  return op_right;
        if(op_right==0) return op_left;

        if(value[op_left].maior >= value[op_right].maior)
            return op_left;
        else
            return op_right;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    value[0].menor = INF;
    value[0].maior = -1;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> value[i].maior;
        value[i].menor = value[i].maior;
    }

    build(1, 1, n);

    for(int i=0; i<m; i++){
        int op, a, b;

        cin >> op >> a >> b;

        if(op==1){
            update(1, 1, n, b, a);
        }
        else{
            int max1, max2, min1, min2, temp1, temp2;

            // 1
            max1 = query_max(1, 1, n, a, b);

            temp1 = query_min(1, 1, n,      a, max1-1);
            temp2 = query_min(1, 1, n, max1+1,      b);

            min1 = value[temp1].menor<=value[temp2].menor ? temp1 : temp2;

            // 2
            min2 = query_min(1, 1, n, a, b);

            temp1 = query_max(1, 1, n,      a, min2-1);
            temp2 = query_max(1, 1, n, min2+1,      b);

            max2 = value[temp1].maior>=value[temp2].maior ? temp1 : temp2;


            cout << max(value[max1].maior-value[min1].menor, value[max2].maior-value[min2].menor) << "\n";

        }
    }

    return 0;
}
