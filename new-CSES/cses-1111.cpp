// 30/01/24 //
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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e6) + 5;
const ll M1  = (1e9) + 7;
const ll M2  = (1e9) + 9;
const ll p = 31;

ll exp(ll a, ll b, ll m){ // 0^0 = 1
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

int n;
ll prefix[MAXN], sufix[MAXN], inv_p1[MAXN];
ll prefix2[MAXN], sufix2[MAXN], inv_p2[MAXN];

ll f_hash_prefix(int i, int j, ll mod=M1){
    return ( (prefix[j] - prefix[i-1] + mod) * inv_p1[i-1] )% mod;
}
ll f_hash_sufix(int i, int j, ll mod=M1){
    int a = n+1-j, b=n+1-i;
    return ( (sufix[b] - sufix[a-1] + mod) * inv_p1[a-1]   )% mod;
}

ll f_hash_prefix2(int i, int j, ll mod=M2){
    return ( (prefix2[j] - prefix2[i-1] + mod) * inv_p2[i-1] )% mod;
}
ll f_hash_sufix2(int i, int j, ll mod=M2){
    int a = n+1-j, b=n+1-i;
    return ( (sufix2[b] - sufix2[a-1] + mod) * inv_p2[a-1]   )% mod;
}

int solve(int sz){
    for(int i=1; i<=n+1-sz; i++){
        int j = i + sz - 1;

        if(f_hash_prefix(i, j, M1)==f_hash_sufix(i, j, M1) && f_hash_prefix2(i, j, M2)==f_hash_sufix2(i, j, M2)){
            return i;
        }
    }

    return -1;
}

int main(){
    fast_io;

    string s;
    cin >> s;

    n = s.size();

    ll p1 = 1, p2=1;
    ll inv1 = exp(p, M1-2, M1), inv2 = exp(p, M2-2, M2);
    inv_p1[0] = inv_p2[0] =  1;

    for(int i=0; i<n; i++){
        ll  c = (ll) (s[i]     - 'a') + 1;
        ll bc = (ll) (s[n-1-i] - 'a') + 1;
        
        prefix[i+1] = (prefix[i] + c*p1)%M1;
        sufix[i+1]  = (sufix[i]  + bc*p1)%M1;

        prefix2[i+1] = (prefix2[i] + c*p2)%M2;
        sufix2[i+1]  = (sufix2[i]  + bc*p2)%M2;

        p1 = (p1*p)%M1;
        p2 = (p2*p)%M2;
        
        inv_p1[i+1] = (inv_p1[i] * inv1)%M1;
        inv_p2[i+1] = (inv_p2[i] * inv2)%M2;
    }   
    
    // bb nos impares
    int l=1, r = (n+1)/2, sz=-1, pos=-1;

    while(l<=r){
        int mid = (l+r)/2;
        int imid = 2*mid-1;
        int tpos = solve(imid);

        if(tpos!=-1){
            l = mid+1;

            if(imid>sz){
                sz = imid;
                pos = tpos;
            }
        }
        else{
            r = mid-1;
        }
    }

    //bb nos pares
    l=1, r = n/2;
    while(l<=r){
        int mid = (l+r)/2;
        int imid = 2*mid;
        int tpos = solve(imid);

        if(tpos!=-1){
            l = mid+1;

            if(imid>sz){
                sz = imid;
                pos = tpos;
            }
        }
        else{
            r = mid-1;
        }
    }

    for(int i=pos-1; i<pos-1+sz; i++)
        cout << s[i];
    cout << endl;

    return 0;
}
