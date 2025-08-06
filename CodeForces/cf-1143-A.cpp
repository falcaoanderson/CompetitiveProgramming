/*
06/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

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

    int left=0, right=0;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v[i]=x;
        if(x){
            right++;
        }
        else{
            left++;
        }
    }

    for(int i=0; i<n; i++){
        if(v[i]){
            right--;
        }
        else{
            left--;
        }

        if(right==0 || left==0){
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
