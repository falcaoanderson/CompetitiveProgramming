// 21/10/20 // 6:22 PM //

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
    vector<int> v(n+1);

    for(int s=0; s<m; s++){
        int p, d;
        cin >> p >> d;

        for(int i=p; i<=n; i+=d) v[i] = 1;
        for(int i=p; i>=1; i-=d) v[i] = 1;
    }

    for(int i=1; i<=n; i++)
        cout << v[i] << endl;

    return 0;
}

