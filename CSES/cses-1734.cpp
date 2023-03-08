// 02/09/19 // 9:32 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, q;
int value[MAXN];
set<int> seg[3*MAXN];

void build(int no, int i, int j){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(i==j){
        seg[no].insert(value[i]);
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        seg[no].insert(seg[left].begin(), seg[left].end());
        seg[no].insert(seg[right].begin(), seg[right].end());
    }
}

set<int> query(int no, int i, int j, int a, int b){
    int mid   = (i+j)/2;
    int left  = 2*no;
    int right = 2*no+1;

    if(i>j || a>b || b<i || j<a){
        set<int> temp;
        return temp;
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        set<int> op_left  = query( left,     i, mid, a, b);
        set<int> op_right = query(right, mid+1,   j, a, b);

        op_left.insert(op_right.begin(), op_right.end());

        return op_left;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> value[i];

    build(1, 1, n);

    while(q--){
        int a, b;
        cin >> a >> b;

        set<int> temp = query(1, 1, n, a, b);

        cout << temp.size() << "\n";
    }

    return 0;
}
