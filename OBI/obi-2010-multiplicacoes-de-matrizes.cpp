// 27/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;

ll n, p, q, r, s, x, y, ii, jj;

int main(){
    fast_io;

    cin >> n >> p >> q >> r >> s >> x >> y >> ii >> jj;

    ll val = 0LL;

    for(int i=1; i<=n; i++)
        val +=  ((p*ii + q*i)%x) * ((r*i + s*jj)%y);       //A[ii][i] * B[i][jj]
        
    cout << val << endl;

    return 0;
}
