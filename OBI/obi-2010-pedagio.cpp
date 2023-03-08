// 27/10/20 // 12:09 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int l, d, k, p;
    cin >> l >> d >> k >> p;
    
    cout << l*k + (l/d)*p << endl;  

    return 0;
}
