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
#define int long long

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(2e5) + 10;

int v[MAXN];

void solve(){
   int n;
   cin >> n;

   for(int i=0; i<n; i++)
        cin >> v[i];

   cout << max(v[n-1] * v[n-2] * v[n-3], v[0]*v[1]*v[n-1]) << endl;
}

int32_t main(){
    fastio;


    solve();

    return 0;
}
