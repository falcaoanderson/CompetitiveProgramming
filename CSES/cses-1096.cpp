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

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;
const ll  MOD  = (1e9) + 7;

matrix prod(matrix a, matrix b){ 
    int x = a.size(), y = b[0].size(), p = b.size();

    matrix c(x, vector<ll>(y, 0LL));

    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            for(int k=0; k<p; k++){
                c[i][j] += (a[i][k] * b[k][j])%MOD;
                c[i][j] %= MOD;
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

    matrix ma = {{1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0},
                {0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 1, 0}};
    matrix m_base{{32},
                  {16},
                  {8},
                  {4},
                  {2},
                  {1}};

    ll n;
    cin >> n;
    
    if(n<=6)
        cout << m_base[6-n][0] << endl;
    else{
        ma = expM(ma, n-6LL);
        m_base = prod(ma, m_base);

        cout << m_base[0][0] << endl;
    }
    
    return 0;
}