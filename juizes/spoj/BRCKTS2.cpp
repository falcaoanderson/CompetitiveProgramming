/*
10/02/26 

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
    string s;
    cin >> s;
    int n = s.size();

    stack<pii> pilha;

    ll ans = 0;

    for(int i=0; i<n; i++){
        char c = s[i];

        if(c == '('){
            pilha.push({i, 1});
        }
        else{
            pii aux = pilha.top(); 
            pilha.pop();
            
            if(pilha.size()&1) ans -= (ll)(i - aux.FF) * (ll)aux.SS;  
            else               ans += (ll)(i - aux.FF) * (ll)aux.SS;  

            if(!pilha.empty() && pilha.top().SS < aux.SS + 1){
                pii temp = {pilha.top().FF, aux.SS + 1};
                pilha.pop();
                pilha.push(temp);
            }
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
