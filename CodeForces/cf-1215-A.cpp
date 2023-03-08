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

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;

void solve(){
    int p1, p2, k1, k2, n;

    cin >> p1 >> p2 >> k1 >> k2 >> n;

    int ma=-1;
    for(int i=0; i<=p1; i++){
        for(int j=0; j<=p2; j++){
            if(i*k1 + j*k2<=n){
                ma = max(ma, i+j);
            }
        }
    }

    int mi = max(n -(k1-1)*p1 -(k2-1)*p2, 0);

    cout << mi << " " << ma << endl;
}

int main(){
    fastio;

    solve();

    return 0;
}
