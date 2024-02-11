// 02/02/24 //
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
const ll MOD  = (1e6);

vector<vector<ll>> prod(vector<vector<ll>> &a, vector<vector<ll>> &b){ // A * B = C
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
    vector<vector<ll>> r=a;
    for(int i=0; i<(int)a.size(); i++){
        for(int j=0; j<(int)a[0].size(); j++){
            if(i==j) r[i][j] = 1LL;
            else     r[i][j] = 0LL;
        }
    }

    while(b>0LL){
        if(b&1LL){
            r = prod(r,a);
            b--;
        }
        else{
            a = prod(a, a);
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;

    ll n, k, l;
    while(cin >> n >> k >> l){
        if(n==0LL) break;
    
        n /= 5LL;
        k %= MOD;
        l %= MOD;

        vector<vector<ll>> ma = {{k, l}, {1LL, 0LL}};
        
        ma = expM(ma, n-1LL);
        ll resp = (ma[0][0]*k + ma[0][1]*1LL)%MOD;
        
        /*
        cout.width(6);
        cout.fill('0');
        cout << resp << endl;
        */

        ll aux = resp;
        int cnt=6;
        while(aux>0){
            cnt--;
            aux /= 10LL;
        }
        while(cnt--){
            cout << 0;
        }

        if(resp!=0) cout << resp;
        cout << endl;
    }

    return 0;
}