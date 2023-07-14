// 13/07/23 //
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

const int MAXN = (2e5) + 5;
const int LOGMAXK = 30;

int path[MAXN][LOGMAXK+5];

int main(){
    fast_io;

    int n, q;
    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> path[i][0];

    for(int k=1; k<LOGMAXK; k++){
        for(int i=1; i<=n; i++){
            path[i][k] = path[ path[i][k-1] ][k-1];
        }
    }

    while(q--){
        int u, k;
        cin >> u >> k;
        
        for(int i=LOGMAXK-1; i>=0; i--){
            if(k>=(1<<i)){
                u = path[u][i];
                k-= (1<<i);
            }
        }

        cout << u << endl;
    }

    return 0;
}
