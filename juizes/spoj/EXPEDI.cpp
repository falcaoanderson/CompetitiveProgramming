/*
09/02/26 

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

void solve(){
    int n;
    cin >> n;
    vector<pii> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i].FF >> v[i].SS; 
    }
    int d, gas;
    cin >> d >> gas;

    for(int i=0; i<n; i++){
        v[i].FF = d - v[i].FF;
    }
    sort(v.begin(), v.end());

    priority_queue<int> fila;
    int ans = 0, l=0;

    while((l < n || !fila.empty()) && gas < d){
        while(l < n && v[l].FF <= gas){
            fila.push(v[l].SS);
            l++;
        }

        if(fila.empty()){
            ans = -1;
            break;
        }
        else{
            gas += fila.top();
            fila.pop();
            ans++;
        }
    }

    cout << ans << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
