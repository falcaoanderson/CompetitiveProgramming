/*
03/03/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;
 
struct Matrix{
    vector<vector<ll>> v;
 
    Matrix(){}
    Matrix(int n, int m, ll start_val = 0LL){
        v.assign(n, vector<ll>(m, start_val));
    }
    Matrix(vector<vector<ll>> x){
        v = x;
    }
 
    Matrix operator*(const Matrix &x){
        int n = v.size(), m = x.v[0].size(), L = v[0].size();
        Matrix temp(n, m, LINF);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<L; k++){
                    temp.v[i][j] = min(temp.v[i][j], v[i][k] + x.v[k][j]);
                }
            }
        }
        return temp;
    }
 
    Matrix expo(int b){
        Matrix a(v), r;
        for(int i=0; i<32; i++){
            if(((1<<i) & b) != 0){
                if(r.v.empty()) r = a;
                else            r = r * a;
            }
            a = a * a;
        }
        return r;
    }
 
    void print(){
        for(auto l: v){
            for(int x: l){
                cout << x << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};      
 
int main(){
    fast_io;
    
    int n, m, k;
    cin >> n >> m >> k;

    Matrix A(n, n, LINF);
    for(int i=0; i<m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
 
        A.v[a-1][b-1] = min(A.v[a-1][b-1], c);
    }

    ll ans = A.expo(k).v[0][n-1];
    cout << (ans < LINF? ans: -1)  << endl;
    
    return 0;
}