// 14/11/20 // xx:xx PM //

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
const int MOD = (1e9) + 7;

ll exp(ll a, int b){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1))%MOD;
    else    return exp((a*a)%MOD, b/2)%MOD;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;

        cout << exp(a, b) << endl;
    }
    
    return 0;
}
