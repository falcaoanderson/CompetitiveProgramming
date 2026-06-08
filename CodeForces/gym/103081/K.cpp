/*
31/01/26

*/

#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD1 = 1e9+7;
const ll MOD2 = 1e9+9;
const ll p = 31;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n;
int find_ans(vector<ll>& s, int m){
    unordered_set<ll, custom_hash> hash, bad;
    ll maxpot1 = 1, maxpot2 = 1;
    for(int i=1; i<m; i++){
        maxpot1 = (maxpot1 * p) % MOD1;
        maxpot2 = (maxpot2 * p) % MOD2;
    }

    ll crr1=0, crr2=0;
    for(int i=0; i<m; i++){
        crr1 = ((crr1 * p) % MOD1 + s[i]) % MOD1;
        crr2 = ((crr2 * p) % MOD2 + s[i]) % MOD2;
    }
    hash.insert(crr1+crr2);

    for(int i=m; i<n; i++){
        crr1 = (crr1 - (maxpot1 * s[i-m]) % MOD1 + MOD1) % MOD1;
        crr1 = ((crr1 * p) % MOD1 + s[i]) % MOD1;

        crr2 = (crr2 - (maxpot2 * s[i-m]) % MOD2 + MOD2) % MOD2;
        crr2 = ((crr2 * p) % MOD2 + s[i]) % MOD2;

        if(hash.find(crr1+crr2)!=hash.end()){
            bad.insert(crr1+crr2);
        }
        hash.insert(crr1+crr2);
    }

    int ans = -1;
    crr1=0, crr2=0;
    for(int i=0; i<m; i++){
        crr1 = ((crr1 * p) % MOD1 + s[i]) % MOD1;
        crr2 = ((crr2 * p) % MOD2 + s[i]) % MOD2;
    }
    if(bad.find(crr1+crr2)==bad.end()){
        ans = m-1;
    }
    for(int i=m; i<n && ans==-1; i++){
        crr1 = (crr1 - (maxpot1 * s[i-m]) % MOD1 + MOD1) % MOD1;
        crr1 = ((crr1 * p) % MOD1 + s[i]) % MOD1;

        crr2 = (crr2 - (maxpot2 * s[i-m]) % MOD2 + MOD2) % MOD2;
        crr2 = ((crr2 * p) % MOD2 + s[i]) % MOD2;

        if(bad.find(crr1+crr2)==bad.end()){
            ans = i;
            break;
        }
    }

    return ans;
}

int main(){
    fast_io;
    
    string s;
    cin >> s;
    n = s.size();
    vector<ll> v(n);
    for(int i=0; i<n; i++) v[i] = (ll)(s[i] - 'A') + 1LL;

    int l=1, r=n, mid;
    int pos_ans = -1, len_ans = -1;
    while(l<=r){
        mid = (l+r) / 2;
        int crr = find_ans(v, mid);

        if(crr != -1){
            len_ans = mid;
            pos_ans = crr;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    if(pos_ans == -1){
        cout << "merda" << endl;
        return 0;
    }

    for(int i=pos_ans-len_ans+1; i<=pos_ans; i++){
        cout << s[i];
    }
    cout << endl;

    return 0;
}