/*
23/04/26 

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

pii calc(string &s){
    int n = SZ(s);
    pii ans = {0, 0};
    
    stack<int> pilha;
    for(int i=0; i<n; i++){
        char c = s[i];

        if(c == '('){
            pilha.push(i);   
        }
        else{
            int crr = pilha.top();
            pilha.pop();
            
            if(crr == i-1){
                ans.SS++;
            }

            if(crr == n-1-i){
                ans.FF++;
            }
            else{
                ans.FF = 0;
            }
        }
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    auto p1 = calc(s1), p2 = calc(s2);
    
    cout << (p1 == p2? "YES": "NO") << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}