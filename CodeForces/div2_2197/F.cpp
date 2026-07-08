/*
13/02/26 

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

vector<pii> aux = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pii> pos = {{0, 0}};
    int cnt = 0;

    for(char c: s){
        int dx = 0, dy = 0;

        if(c == '(') dx++;
        if(c == ')') dx--;
        if(c == '[') dy++;
        if(c == ']') dy--;

        vector<pii> new_pos;
        for(pii p: pos){
            if(p.FF + dx >= 0 && p.SS + dy >= 0) 
                new_pos.PB({p.FF + dx, p.SS + dy});
        }

        if(new_pos.empty()){
            cnt++;

            for(pii p: pos){
                for(pii d: aux){
                    if(p.FF + d.FF >= 0 && p.SS + d.SS >= 0) 
                        new_pos.PB({p.FF + d.FF, p.SS + d.SS});
                }
            }
        }

        swap(pos, new_pos);
    }

    int ans = INF;
    for(pii p: pos) ans = min(ans, cnt + (p.FF + p.SS) / 2);
    
    cout << ans << endl;
}

int main(){
    fast_io;
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
