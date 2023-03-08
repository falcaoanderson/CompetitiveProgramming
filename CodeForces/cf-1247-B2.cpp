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

const int INF  = 0x3f3f3f3f;
const int MAXN = (int)(1e6) + 10;

void solve(){
    int n, k, d;

    cin >> n >> k >> d;

    vector<int> v(n+1);
    map<int, int> qnt;
    int resp=INF, atual=0;

    for(int i=1; i<=n; i++) cin >> v[i];

    for(int i=1; i<=n; i++){
        int a = v[i];

        if(i<=d){
            qnt[a]++;
            if(qnt[a]==1)atual++;
        }
        if(i>d && a!=v[i-d]){
            qnt[v[i-d]]--;
            qnt[a]++;

            if(qnt[v[i-d]]==0) atual--;
            if(     qnt[a]==1) atual++;
        }

        if(i>=d) resp = min(resp, atual);
    }

    cout << resp << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
