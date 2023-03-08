// 21/10/20 // 6:30 PM //

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

    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > v(n);

    for(int i=0; i<n; i++){
        v[i].second = i+1;
        for(int j=0; j<m; j++){
            int temp;
            cin >> temp;

            v[i].first += temp;
        }
    }
    sort(v.begin(), v.end());

    cout << v[0].second << endl;

    return 0;
}

