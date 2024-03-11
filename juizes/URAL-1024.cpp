/*
11/03/24 
Problem: URAL - Permutations
Complexity: O(n^2)
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

ll mmc(ll a, ll b){
    return (a*b)/__gcd(a, b);
}

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> p(n+1), crr(n+1), aux(n+1), cicle(n+1);

    for(int i=1; i<=n; i++){
        cin >> p[i];
        crr[i] = aux[i] = i;
    }

    for(int j=1; j<=n+2; j++){
        for(int i=1; i<=n; i++){
            crr[i] = aux[p[i]];

            if(crr[i]==i && cicle[i]==0) cicle[i] = j;
        }
        aux = crr;
    }

    ll resp = 1;
    for(int i=1; i<=n; i++){
        resp = mmc(resp, (ll)cicle[i]);
    }

    cout << resp << endl;
    
    return 0;
}
