// 29/12/19 // 8:28 PM //

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define endl "\n"
#define MRL int mid=(i+j)/2, left=2*no, right=2*no+1

const int MAXN = 1e4 + 10;

int n, q;
vector<int> seg[MAXN];
vector<int> v(MAXN);

void build(int no, int i, int j){
    MRL;

    if(i==j){
        seg[no].pb(v[i]);
    }
    else{
        build( left,     i, mid);
        build(right, mid+1,   j);

        merge(seg[left].begin(), seg[left].end(),
                seg[right].begin(), seg[right].end(),
                back_inserter(seg[no])
              );
    }
}
vector<int> query(int no, int i, int j, int a, int b){
    MRL;

    if(b<i || j<a){
        vector<int> u = {};
        return u;
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        vector<int> u_l = query(left, i, mid, a, b);
        vector<int> u_r = query(right, mid+1, j, a, b);

        vector<int> u;
        merge(u_l.begin(), u_l.end(), u_r.begin(), u_r.end(), back_inserter(u));

        return u;
    }
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++) cin >> v[i];

    build(1, 1, n);

    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;

        vector<int> resp = query(1, 1, n, a, b);

        for(int i : resp)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
