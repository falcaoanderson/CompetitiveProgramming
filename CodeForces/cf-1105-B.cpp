/*
30/08/25 

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

    int n, k;
    cin >> n >> k;

    vector<int> freq(26);
    int crr=0, last=0;
    for(int i=0; i<n; i++){
        char c;
        cin >> c;
        int val = c-'a';

        if(val==last || i==0){
            crr++;

            if(crr==k){
                freq[val]++;
                crr = 0;
            }
        }
        else{
            crr = 1;
        }

        last = val;
    }

    int resp = 0;
    for(int i=0; i<26; i++){
        resp = max(resp, freq[i]);
    }
    cout << resp << endl;

    return 0;
}
