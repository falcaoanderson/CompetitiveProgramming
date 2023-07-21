// 21/07/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (1e6) + 5;
const ll MOD  = (1e9) + 7;

ll fat[MAXN], ifat[MAXN];

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

    string s;
    cin >> s;

    int n=s.size();
    vector<int> count(26);
    for(int i=0; i<n; i++) count[(int)s[i]-97]++;

    fat[0] = 1LL;
    for(ll i=1LL; i<=n; i++) fat[i] = (fat[i-1] * i)%MOD;
    
    ifat[n] = exp(fat[n], MOD-2);
    for(ll i=n-1; i>=0; i--) ifat[i] = (ifat[i+1] * (i+1LL))%MOD;

    ll resp = fat[n];
    for(int i=0; i<26; i++) resp = (resp * ifat[count[i]])%MOD;

    cout << resp << endl;

    return 0;
}
