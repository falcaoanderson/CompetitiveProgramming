/*
12/09/25 

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

int main(){
    fast_io;

    int n;
    cin >> n;

    map<int, int> myset;

    ll resp = n;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;

        int b = a + i;

        if(myset.find(b)!=myset.end()){
            resp += (ll)(2*myset[b]);
        }
        else{
            myset[b] = 0;
        }
        if(myset.find(b-n)!=myset.end()){
            resp += (ll)(2*myset[b-n]);
        }

        myset[b]++;
    }

    cout << resp << endl;

    return 0;
}
