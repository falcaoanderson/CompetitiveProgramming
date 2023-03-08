// 26/11/20 // xx:xx PM //

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

ll exp(ll a, ll b, ll m=MOD){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1, m))%m;
    return exp((a*a)%m, b/2, m)%m;
}

int main(){
    fast_io;

    int n;
    cin >> n;

    int resp =  0;

    for(int i=2; i<=n; i++){
        if((n+i-1)%(2*i-1)==0){
            if((n+i-1)/(2*i-1)<i) break;
            resp ++;
        }
    }

    cout << resp << endl;

    return 0;
}
