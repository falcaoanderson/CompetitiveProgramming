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
    int n;
    string room;
    cin >> n >> room;

    int left = INF, right = -INF;

    for(int i=0; i<n; i++)
        if(room[i]=='1'){
            left = i;
            break;
        }
    for(int i=n-1; i>=0; i--)
        if(room[i]=='1'){
            right = i;
            break;
        }


    cout << max(n,2*max(n-left, right+1)) << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
