// 26/10/20 // 8:41 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        v.pb(mp(a, 1));
        v.pb(mp(b, 0));
    }

    sort(v.begin(), v.end());

    int resp=0, atual = 0;

    for(int i=0; i<2*n; i++){
        if(v[i].second==0) atual--;
        else               atual++;

        resp = max(resp, atual);
    }

    cout << resp << endl;

    return 0;
}

