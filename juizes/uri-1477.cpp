// 28/08/19 // 4:15 PM //

#include <bits/stdc++.h>

using namespace std;


#define MAXN 100010
#define MAXT 5
#define pb push_back

int n, m;
int  value[MAXN];
int  seg[3*MAXN][MAXT];
int lazy[3*MAXN];

int mod(int a, int b){
    if( (a%b)>=0) return a%b;
    else    return b +a%b;
}

void build(int no, int i, int j){

    lazy[no] = 0;

    if(i==j){
        seg[no][0] = 1;
        seg[no][1] = seg[no][2] = value[i]  = 0;
    }
    else{
        int mid   = (i+j)/2;
        int left  = 2*no;
        int right = 2*no+1;

        build( left,     i, mid);
        build(right, mid+1,   j);

        for(int k=0; k<3; k++)
            seg[no][k] = seg[left][k] + seg[right][k];
    }
}

void push(int no, int i, int j){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    int temp[MAXT];
    for(int k=0; k<3; k++) temp[k] = seg[no][k];
    for(int k=0; k<3; k++) seg[no][k] = temp[ mod(k-lazy[no], 3) ];

    if(i!=j){
        lazy[left]  += lazy[no];
        lazy[right] += lazy[no];
    }

    lazy[no] = 0;
}

void update(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(lazy[no]) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return;
    }
    else if(a<=i && j<=b){
        lazy[no]++;

        push(no, i, j);
    }
    else{
        update( left,     i, mid, a, b);
        update(right, mid+1,   j, a, b);

        for(int k=0; k<3; k++)
            seg[no][k] = seg[left][k] + seg[right][k];
    }
}

vector<int> query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;
    vector<int> temp = {-1, -1, -1};

    if(lazy[no]) push(no, i, j);

    if(i>j || a>b || b<i || j<a){
        return temp;
    }
    else if(a<=i && j<=b){
        for(int k=0; k<3; k++) temp[k] =  seg[no][k] ;
        return temp;
    }
    else{
        vector<int> op_left, op_right;

        op_left  = query( left,     i, mid, a, b);
        op_right = query(right, mid+1,   j, a, b);

        if(op_left[0]  == -1) return op_right;
        if(op_right[0] == -1) return op_left;

        for(int k=0; k<3; k++)
            temp[k] = op_left[k]+op_right[k];

        return temp;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m){
        //if(n==0) break;
        build(1, 1, n);

        for(int i=0; i<m; i++){
            char op;
            int a, b;

            cin >> op >> a >> b;

            if(op=='M'){
                update(1, 1, n, a, b);
            }
            else{
                vector<int> temp = query(1, 1, n, a, b);
                cout << temp[0] << " " << temp[1] << " " << temp[2] << "\n";
            }

        }
        cout << "\n";
    }

    return 0;
}
