// 29/12/19 // 5:15 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MAXN = 1e5 + 10;

int n;
int h[MAXN], k[MAXN];
int seg[MAXN*4], qnt[MAXN];

void build(int no, int i, int j){
    int left = 2*no, right = 2*no+1, mid = (i+j)/2;

    if(i==j){
        seg[no] = i;
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        seg[no] = qnt[ seg[right] ] <= qnt[ seg[left] ] ? seg[right] : seg[left];
    }
}
void update(int no, int i, int j, int ind, int delta){
    int left  = 2*no, right = 2*no+1, mid   = (i+j)/2;

    if(i==j){
        qnt[i] += delta;
    }
    else{
        if(ind<=mid)
            update( left,     i, mid, ind, delta);
        else
            update(right, mid+1,   j, ind, delta);

        seg[no] = qnt[ seg[right] ] <= qnt[ seg[left] ] ? seg[right] : seg[left];
    }
}
int query(int no, int i, int j, int a, int b){
    int left = 2*no, right = 2*no+1, mid = (i+j)/2;

    if(b<i || j<a){
        return -1;
    }
    else if (a<=i && j<=b){
        return seg[no];
    }
    else{
        int op_l = query(left, i, mid, a, b);
        int op_r = query(right, mid+1, j, a, b);

        if(op_l==-1) return op_r;
        if(op_r==-1) return op_l;

        return qnt[ op_r ] <= qnt[ op_l ] ? op_r : op_l;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int max_h = 0;

    for(int i=1; i<=n; i++){
        cin >> h[i] >> k[i];
        max_h = max(max_h, h[i]);
    }

    build(1, 1, max_h);

    int resp=0;

    for(int i=n; i>=1; i--){

        for(int j=0; j<k[i]; j++){

            int ind = query(1, 1, max_h, 1, h[i]);
            resp += qnt[ind];

            update(1, 1, max_h, ind, 1);
        }
    }


    cout << resp << endl;

    return 0;
}

