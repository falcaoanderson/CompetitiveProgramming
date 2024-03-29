// 12/09/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
 
using namespace std;
 
#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const ll  MOD  = (1e9) + 7;
 
struct Matrix{
    vector< vector<ll> > v;
 
    Matrix(){}
    Matrix(int n, int m){
        v = vector< vector<ll>>(n, vector<ll>(m, 0LL));
    }
    Matrix(vector< vector<ll> > x){
        v = x;
    }
 
    Matrix operator*(const Matrix &x){
        int n = v.size(), m = x.v[0].size(), L=v[0].size();
 
        vector< vector<ll>> temp(n, vector<ll>(m, 0LL));
 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<L; k++){
                    temp[i][j] += (v[i][k] * x.v[k][j])%MOD;
                    temp[i][j] %= MOD;
                }
            }
        }
 
        return Matrix(temp);
    }
 
    Matrix expo(ll b){
        int sz = v.size();
        vector< vector<ll> > va=v, vr(sz, vector<ll>(sz, 0LL));
        for(int i=0; i<sz; i++) vr[i][i] = 1;
 
        Matrix a(va), r(vr);
 
        while(b>0LL){
            if(b&1){
                r = (r*a);
                b--;
            }
            else{
                a = a*a;
                b /= 2LL;
            }
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
    }
};      
 
int main(){
    fast_io;
    
    int n, m, k;
    cin >> n >> m >> k;

    vector< vector<ll> > ma (n, vector<ll> (n, 0LL));

    while(m--){
        int a, b;
        cin >> a >> b;

        ma[a-1][b-1]++;
    }

    Matrix MA(ma);

    cout << (MA.expo(k)).v[0][n-1] << endl;
    
    return 0;
}
