// 17/07/23 //
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

const int INF  = 0x3f3f3f3f;
const int MAXN = (5e4);
const int MOD  = (1e9) + 7;

int last[MAXN+5];

void solve(){
    int m;
    cin >> m;

    memset(last, 0, sizeof(last));

    for(int i=1; i<=m; i++){
        int n;
        cin >> n;

        for(int j=0; j<n; j++){
            int val;
            cin >> val;

            last[val] = i;
        }
    }

    vector<int> resp(m+1);

    for(int i=1; i<=MAXN; i++){
        resp[last[i]] = i;  
    }

    for(int i=1; i<=m; i++){
        if(resp[i]==0){
            cout << -1 << endl;
            return;
        }
    }

    for(int i=1; i<=m; i++){
        cout << resp[i] << " ";
    }
    cout << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
