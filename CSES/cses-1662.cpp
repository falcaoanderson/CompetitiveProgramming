// 29/10/20 // 1:40 PM //

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

ll mod(ll a, ll b){
    a = a%b;
    return (a>=0? a: a+b);
}

int main(){
    fast_io;

    ll n;
    cin >> n;
    
    unordered_map<ll, ll> soma; soma.reserve(2*n);
    soma[0LL] = 1LL;
    ll prefix = 0LL, qnt=0LL;

    for(int i=0; i<n; i++){
        ll val;
        cin >> val;

        prefix = mod(prefix+val, n);
        
        qnt += soma[prefix];

        soma[prefix]++;
    }

    cout << qnt << endl;

    return 0;
}
