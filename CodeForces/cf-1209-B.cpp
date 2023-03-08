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
const int MAXN = (int)(1e5) + 10;

void solve(){
    int n;
    string ini;

    cin >> n >> ini;

    vector<int> a(n), b(n);

    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    int cur=0, best=0;
    //cout << endl;
    for(int t=0; t<=(n*10000); t++){
        for(int i=0; i<n; i++){
            if( (max(0,(t-b[i])/a[i]) + (t>=b[i]) + (int)(ini[i]-'0'))%2 == 1 )
                cur++;
            //cout << (max(0,(t-b[i])/a[i]) + (t>=b[i]) + (int)(ini[i]-'0'))%2 << " ";
        }
        //cout << endl;
        best = max(best, cur);
        cur = 0;
    }
    //cout << endl;
    cout << best << endl;
}

int main(){
    fastio;


    solve();

    return 0;
}
