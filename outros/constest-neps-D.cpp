// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
//#define int long long

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(2e7) + 10;
const int INI = (int)(1e9);

int n, k;

int v[MAXN];

void solve(){
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int xa, ya, xb, yb;

        cin >> xa >> ya >> xb >> yb;

        int tam = abs(xa-xb);

        v[ya+1001]   = tam;
        v[yb+1001 + 1] = -tam;
    }

    for(int i=1; i<=1000010; i++){
        v[i] += v[i-1];
        if(v[i] >= k){
            cout << i - 1001 << endl;
            return;
        }
    }

    cout << "PERDAO MEU REI" << endl;
}

int main(){
    fastio;

    solve();

    return 0;
}
