/*
06/10/25 

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
    
    int n;
    cin >> n;

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;

        int n=SZ(s1), m=SZ(s2);
        int a=0, b=0;
        bool resp = 1;

        while(a<n && b<m){
            if(s1[a]!=s2[b]){
                resp = 0;
                break;
            }

            while(a<n && b<m && s1[a]==s2[b]){
                a++;
                b++;
            }
            while(s2[b]==s2[b-1]){
                b++;
            }
        }
        if(a!=n || b!=m) resp = 0;

        cout << (resp?"YES":"NO") << endl;
    }

    return 0;
}
