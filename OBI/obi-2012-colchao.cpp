// 22/10/20 // 7:09 PM //

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

    int a, b, c, h, l;
    cin >> a >> b >> c >> h >> l;

    if((a<=h && b<=l)||(a<=l && b<=h)||
       (a<=h && c<=l)||(a<=l && c<=h)||
       (b<=h && c<=l)||(b<=l && c<=h))
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}

