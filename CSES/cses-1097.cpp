// 02/11/20 // xx:xx PM //

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
const int MAXN = (5e3) + 10;

int n;
ll v[MAXN], memo[MAXN][MAXN];

int main(){
    fast_io;

    cin >> n;

    for(int i=1; i<=n; i++) cin >> v[i];

    for(int t=0; t<n; t++){
        for(int l=n; l>=1; l--){
            int r = l+t;

            if(((l+r)&1)==((1+n)&1))
                memo[l][r] = max(memo[l+1][r]+v[l], memo[l][r-1]+v[r]);
            else
                memo[l][r] = min(memo[l+1][r], memo[l][r-1]);
        }
    }

    cout << memo[1][n] << endl;

    return 0;
}
