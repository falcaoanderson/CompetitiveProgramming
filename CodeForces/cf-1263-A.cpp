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

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--){
        vector<int> v(3);
        for(int &i : v) cin >> i;
        sort(v.begin(), v.end());

        int resp = 0, dif = v[2] - v[1];

        resp += min(v[0], dif);
        v[2] -= min(v[0], dif);
        v[0] -= min(v[0], dif);

        v[1] -= v[0]/2;
        v[2] -= v[0]/2;

        resp += v[0]/2 + v[0]/2 + min(v[1], v[2]);

        cout << resp << endl;
    }

    return 0;
}
