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
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n;
    cin >> n;
    int ma[n+1][n+1];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ma[i][j];
        }
    }

    for(int i=0; i<n; i++){
        cout << (int)sqrt((ma[i][(i+1)%n]*ma[i][(i+2)%n])/ma[(i+1)%n][(i+2)%n]) << " ";
    }
}

int32_t main(){
    fastio;

    solve();

    return 0;
}
