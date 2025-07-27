/*
26/07/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;
    
    int k;
    cin >> k;

    int n=0, m=0;

    for(int i=5; i<=k; i++){
        if(k%i==0 && k >= 5*i){
            n = i;
            m = k/i;
            break;
        }
    }

    if(n==0){
        cout << -1 << endl;
        return 0;
    }

    string vowels = "aeiou";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << vowels[(i+j)%5];
        }
    }
    cout << endl;
    return 0;
}
