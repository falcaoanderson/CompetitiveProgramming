/*
08/08/25 

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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n);
    vector<pii> vp(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        vp[i] = {v[i], i};
    }

    sort(vp.begin(), vp.end());

    vector<bool> flag(n);
    ll sum = 0;
    for(int i=n-1; i>=n-m*k; i--){
        flag[vp[i].SS] = 1; 
        sum += (ll)vp[i].FF;
    }

    int aux=0, cnt=0;
    vector<int> resp;
    for(int i=0; i<n; i++){
        aux += flag[i];

        if(aux==m && cnt<k-1){
            resp.PB(i+1);
            cnt++;
            aux = 0;
        }
    }

    cout << sum << endl;
    for(int x: resp) cout << x << " ";
    cout << endl;

    return 0;
}
