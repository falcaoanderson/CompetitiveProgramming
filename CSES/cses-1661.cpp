// 29/10/20 // xx:xx PM //

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

int main(){
    fast_io;

    int n;
    ll x;

    cin >> n >> x;
    
    ll prefix = 0LL, qnt=0LL;
    unordered_map<ll, ll> soma; soma.reserve(2*n);
    soma[0] = 1LL;

    for(int i=0; i<n; i++){
        ll val;
        cin >> val;

        prefix += val;
        
        qnt += soma[prefix-x];

        soma[prefix]++;
    }

    cout << qnt << endl;

    return 0;
}
