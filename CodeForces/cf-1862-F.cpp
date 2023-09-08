// 08/09/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (1e2) + 5;
const int MAXM = (1e6) + 5;

int n, w, f, s[MAXN], sum_s;
int memo[5][MAXM];

void solve(){
    cin >> w >> f >> n;

    sum_s = 0;
    for(int i=1; i<=n; i++){
        cin >> s[i];

        sum_s += s[i];
    }

    if(w<f) swap(w, f); // w >= f
    if(w >= sum_s){ // w, f < 1e6
        cout << 1 << endl;
        return;
    }

    memset(memo, 0, sizeof(memo));

    for(int i=0; i<=1e6; i++) memo[0][i] = i;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=1e6; j++){
            
            memo[i&1][j] = memo[(~i)&1][j];
            
            if(s[i]<=j) memo[i&1][j] = min(memo[i&1][j], memo[(~i)&1][j-s[i]]);
        }
    }

    int resp = 1e6;
    for(int w_mana=0; w_mana<=1e6; w_mana++){
        int t = (w_mana+w-1)/w;

        if(sum_s - (w_mana-memo[n&1][w_mana]) <= f*t){
            resp = t;
            break;
        }
    }

    cout << resp << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
