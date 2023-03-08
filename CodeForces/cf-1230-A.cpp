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
    vector<int> v(4);

    for(int i=0; i<4; i++) cin >> v[i];

    bool resp = false;
    for(int i=0; i<(1<<4); i++){
        int s1=0, s2=0;

        for(int k=0; k<4; k++){
            if(i&(1<<k))
                s1+=v[k];
            else
                s2+=v[k];
        }
        if(s1==s2){
            resp = true;
            break;
        }
    }

    if(resp)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    fastio;

    solve();

    return 0;
}
