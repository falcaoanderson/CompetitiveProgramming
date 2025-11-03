/*
07/10/25

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

    string s1, s2;
    cin >> s1 >> s2;

    string vowel = "aeiou";

    bool resp = (SZ(s1) == SZ(s2));
    for(int i=0; i<SZ(s1) && resp; i++){
        bool a=0, b=0;

        for(char c: vowel){
            if(c==s1[i]) a=1;
        }

        for(char c: vowel){
            if(c==s2[i]) b=1;
        }

        if((a^b)==1){
            resp = 0;
        }
    }

    cout << (resp?"Yes":"No") << endl;

    return 0;
}
