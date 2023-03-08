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
    string s, t;
    cin >> s >> t;

    for(char cs : s){
        for(char ct : t){
            if(cs==ct){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
