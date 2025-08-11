/*
09/08/25 

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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int va[MAXN], vb[MAXN], pos_a[MAXN], maxsize[MAXN];

int main(){
    fast_io;

    int n;
    ll f, s;
    cin >> n >> f >> s;

    for(int i=1; i<=n; i++){
        cin >> va[i];
        pos_a[va[i]]=i;
    }

    ll resp = LINF;

    for(int i=1; i<=n; i++){
        cin >> vb[i];

        int aux_pos = pos_a[vb[i]];

        if(va[aux_pos-1] == vb[i-1]){
            maxsize[aux_pos] = maxsize[aux_pos-1] + 1;
        }
        else{
            maxsize[aux_pos] = 1;
        }

        resp = min(
            resp, 
            max( f * (ll)(aux_pos-maxsize[aux_pos] + i-maxsize[aux_pos]), s * (ll)(n-aux_pos + n-i))
        );
    }

    cout << resp << endl;

    return 0;
}
