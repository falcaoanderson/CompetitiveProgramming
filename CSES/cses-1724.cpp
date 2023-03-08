// 17/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef vector<vector<ll>> matrix;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 10;
const ll  MOD  = (1e9) + 7;

matrix prod(matrix a, matrix b){ 
    int x = a.size(), y = b[0].size(), p = b.size();

    matrix c(x, vector<ll>(y, INF));

    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++){
            for(int k=0; k<p; k++){
                c[i][j] = min(c[i][j], (a[i][k] + b[k][j]));
            }
        }

    return c;
}

matrix expM(matrix a, ll b){
    if(b==0){
        for(int i=0; i<(int)a.size(); i++){
            for(int j=0; j<(int)a[0].size(); j++){
                if(i==j) a[i][j] = 1;
                else     a[i][j] = 0;
            }
        }
        return a;
    }
    if(b==1){
        return a;
    }

    if(b&1) return prod(a, expM(a, b-1LL));
    return expM(prod(a, a), b/2LL);
}

int main(){
    fast_io;

    int n, m, k;
    cin >> n >> m >> k;

    matrix ma(n+1, vector<ll>(n+1, INF));
    
    while(m--){
        int a, b; ll c;
        cin >> a >> b >> c;

        ma[a][b] = min(ma[a][b], c);    
    }

    ma = expM(ma, k);

    if(ma[1][n]==INF) cout << -1 << endl;
    else              cout << ma[1][n] << endl;

    return 0;
}