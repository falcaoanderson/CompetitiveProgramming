/*
10/10/25 

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
    
    vector<int> v;
    v.PB(0);
    for(int i=0; i<n; i++){
        int val; cin >> val;
        v.PB(val);
    }
    v.PB(1001);

    int resp = 0, qnt=0;
    for(int i=1; i<=n; i++){
        if(v[i-1]+1==v[i] && v[i]+1==v[i+1]){
            qnt++;
        }
        else{
            resp = max(resp, qnt);
            qnt = 0;
        }
    }
    resp = max(resp, qnt);

    cout << resp << endl;

    return 0;
}
