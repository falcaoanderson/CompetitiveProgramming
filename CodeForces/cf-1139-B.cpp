/*
05/08/25 

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
const int MAXN = (1e2) + 5;
const int MOD  = (1e9) + 7;

int ma[MAXN][MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    ll resp = 0;
    int aux=INF;
    for(int i=n-1; i>=0; i--){
        aux = max(0, min(v[i], aux-1));
        resp += (ll)aux;
    }

    cout << resp << endl;

    return 0;
}
