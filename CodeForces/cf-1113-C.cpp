/*
15/08/25 

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
const int MAXV = (1<<20) + 5;
const int MOD  = (1e9) + 7;

int qnt[MAXV][5];

int main(){
    fast_io;


    int n;
    cin >> n;

    ll resp = 0;
    int acum = 0;
    qnt[0][0] = 1;
    for(int i=1; i<=n; i++){
        int val;
        cin >> val;

        acum = acum^val;

        resp += (ll)qnt[acum][i&1];
        qnt[acum][i&1]++;
    }
    
    cout << resp << endl;

    return 0;
}
