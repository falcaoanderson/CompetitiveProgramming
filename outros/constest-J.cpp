#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define MRL int left = 2*no, right=2*no+1, mid=(i+j)/2

const int MAXN = 1e5 + 5;

int n, q;
int v[MAXN];
vector<int> seg[4*MAXN];

void build(int no, int i, int j){
    if(i==j){
        seg[no].pb(v[i]);
    }
    else{
        MRL;
        build(left, i, mid);
        build(right, mid+1, j);

        merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(), back_inserter(seg[no]));
    }
}

int query(int no, int i, int j, int a, int b, int delta){

    if(j<a || b<i){
        return 0;
    }
    else if(a<= i && j <=b){
        return seg[no].end()-upper_bound(seg[no].begin(), seg[no].end(), delta);
    }
    else{
        MRL;
        int op1 = query( left,     i, mid, a, b, delta);
        int op2 = query(right, mid+1,   j, a, b, delta);

        return op1 + op2;
    }
}
void update(int no, int i, int j, int pos, int delta){
    if(i==j){
        seg[no][0] = delta;
    }
    else{
        MRL;
        if(pos<=mid) update(left, i, mid, pos, delta);
        else         update(right, mid+1, j, pos, delta);

        seg[no].clear();
        merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(), back_inserter(seg[no]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> v[i];

    build(1, 1, n);

    int tipo, a, b, delta;
    while(q--){

        cin >> tipo;

        if(tipo==1){
            cin >> a >> delta;

            update(1, 1, n, a, delta);
        }
        else{
            cin >> delta >> a >> b;

            cout << query(1, 1, n, a, b, delta) << endl;
        }
    }

    return 0;
}
