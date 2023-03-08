// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v[i]-=temp;
    }

    bool possivel=1;
    int l=-1, r=-1;

    for(int i=0; i<n; i++)
        if(v[i]!=0){
            l = i;
            break;
        }
    for(int i=n-1; i>=0; i--)
        if(v[i]!=0){
            r = i;
            break;
        }

    if(l!=-1)
        for(int i=l; i<=r; i++)
            if(v[i]>=0 || (i>l && v[i]!=v[i-1])) possivel = 0;

    if(possivel)
        cout << "YES\n";
    else
        cout << "NO\n";

}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
