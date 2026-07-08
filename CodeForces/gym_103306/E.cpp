/*
11/04/26

*/
#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define endl '\n'
#define FF first
#define SS second

typedef long long ll;
typedef pair<int, int> pii;

void solve(){
    int n;
    string c;
    cin >> n >> c;

    ll total = 0;
    for(int i=0; i<=(int)c.size()-2; i++){
        total = 10LL * total + (ll)(c[i]-'0');
    }

    if(c[(int)c.size()-1] == 'G'){
        total *= (1LL << 10);
    }
    else if(c[(int)c.size()-1] == 'T'){
        total *= (1LL << 20);
    }

    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    vector<int> aux(n);
    ll r=-1, wind = 0;
    for(int l=0; l<n; l++){
        while(r+1 < n && wind+v[r+1] <= total){
            wind += v[r+1];
            r++;
        }
        aux[l] = r - l + 1;
        wind -= v[l];
    }

    int crr = 1e9, ans_r;
    for(int i=0; i<n; i++){
        crr = min(crr, aux[i]);
        if(i + crr - 1 == n - 1){
            ans_r = crr;
            break;
        }
    }

    int ans_l = -1;
    for(int i=0; i<n; i++){
        if(aux[i] < ans_r + 1 && i+aux[i]-1 < n-2){
            ans_l = i+1;
            break;
        }
    }

    cout << ans_r << " " << ans_l << endl;
}


int main() {
    fast_io;

    solve();

    return 0;
}