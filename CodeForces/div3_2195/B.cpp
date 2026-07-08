/*
15/02/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }

        bool ans = 1;
        for(int i=1; i<=n/2 && ans; i++){
            int x = i;
            bool flag = (x==i);
            while((x % 2) == 0){
                x /= 2;
                if(x==i) flag = 1;
            }

            if(!flag) ans = 0;

            for(int j=i; j<=n && ans; j*=2){
                int y = v[j];
                
                if( (y % x) != 0){
                    ans = 0;
                }
                else{
                    y /= x;

                    if(y != (y&(-y))){
                        ans = 0;
                    }
                }

                v[j] = 0;
            }
        }

        for(int i=n/2 + 1; i<=n && ans; i++){
            if(v[i] != 0 && v[i]!=i){
                ans = 0;
            }
        }

        cout << (ans? "YES": "NO") << endl; 
    }

    return 0;
}
