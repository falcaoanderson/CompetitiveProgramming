/*
13/08/25 

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
#define sz(x) (int)(x).size()

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

    vector<int> pos1(n+1), pos2(n+1);
    for(int i=1; i<=2*n; i++){
        int val;
        cin >> val;

        if(pos1[val]==0) pos1[val] = i;
        else pos2[val] = i;
    }

    int a=1, b=1;
    ll resp = 0;
    for(int i=1; i<=n; i++){
        int op1 = abs(pos1[i]-a) + abs(pos2[i]-b);
        int op2 = abs(pos2[i]-a) + abs(pos1[i]-b);
        
        resp += (ll)min(op1, op2);
        a = pos1[i];
        b = pos2[i];
    }

    cout << resp << endl;

    return 0;
}
