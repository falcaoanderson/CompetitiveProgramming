// 17/11/20 // xx:xx PM //

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
const int MAXN = (1e5) + 10;
const ll MOD  = (1e9) + 7;

vector<vector<ll>> prod(vector<vector<ll>> a, vector<vector<ll>> b){ // A * B = C
    // A == x*p // B == p*y // c == x*y
    int x = a.size(), y = b[0].size(), p = b.size();

    vector<vector<ll>> c(x, vector<ll>(y, 0));
    //if(a[0].size()!=p) return c; nao existe produto

    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            for(int k=0; k<p; k++){
                c[i][j] += (a[i][k] * b[k][j])%MOD;
                c[i][j] %= MOD;
            }

    return c;
}

vector<vector<ll>> expM(vector<vector<ll>> a, ll b){
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

    if(b&1)
        return prod(a, expM(a, b-1));
    return expM(prod(a, a), b/2);
}

void printM(vector<vector<ll>> a){
    for(int i=0; i<(int)a.size(); i++){
        for(int j=0; j<(int)a[0].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    fast_io;

    vector<vector<ll>> ma = {{1, 1}, {1, 0}};
    
    ll n;
    cin >> n;

    if(n==0LL){ 
        cout << 0 << endl;
    }
    else if(n==1LL){ 
        cout << 1 << endl;
    }
    else{
        ma = expM(ma, n-2LL);
        cout << (ma[0][0] + ma[0][1])%MOD << endl;
    }

    return 0;
}