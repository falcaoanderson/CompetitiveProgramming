// 21/10/20 // 6:57 PM //

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

    int a, b, c, x, y, z;

    cin >> a >> b >> c >> x >> y >> z;

    cout << (x/a)*(y/b)*(z/c) << endl;

    return 0;
}
