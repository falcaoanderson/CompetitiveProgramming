// 18/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;
const int MOD  = (1e9) + 7;

int n, q, ma[MAXN][MAXN], bit[MAXN][MAXN];

void update(int x, int y, int val){
    for(int i=x; i<=n; i+=(i&-i))
        for(int j=y; j<=n; j+=(j&-j))
            bit[i][j] += val;
}

int query(int x, int y){
    int sum=0;

    for(int i=x; i>0; i-=(i&-i))
        for(int j=y; j>0; j-=(j&-j))
            sum += bit[i][j];

    return sum;
}

int main(){ // O( (n^2*log^2(n) + q*log^2(n) )
    fast_io;

    cin >> n >> q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c; 
            cin >> c;

            if(c=='*'){
                update(i, j, 1);
                ma[i][j] = 1;
            }
        }
    }

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int x, y;
            cin >> x >> y;

            if(ma[x][y]==1) update(x, y, -1);
            else            update(x, y,  1);

            ma[x][y] = ~ma[x][y]&1;
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            cout << query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1) << endl;
        }
    }

    return 0;
}
