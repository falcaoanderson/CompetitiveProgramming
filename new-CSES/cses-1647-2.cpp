// 03/05/23 // sparse table // O(n*log(n) + q)
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

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;
const int MAXLOG = 17 + 5;

int sparse[MAXN][MAXLOG];

int main(){
    fast_io;

    int n, q;
    cin >> n >> q;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    // build min sparse table
    for(int i=1; i<=n; i++) sparse[i][0] = v[i];
    for(int l=1; (1<<l) <= n; l++){
        for(int i=1; i+(1<<l)-1 <= n; i++){
            sparse[i][l] = min(sparse[i][l-1], sparse[i+(1<<(l-1))][l-1]);
        }
    }
    // -------------------
    vector<int> log(n+1);
    for(int l=1; (1<<l) <= n; l++) log[(1<<l)] = 1;
    for(int i=1; i<=n; i++) log[i] += log[i-1];
    
    while(q--){
        int a, b;
        cin >> a >> b;

        int l = log[b-a+1];
        
        cout << min(sparse[a][l], sparse[b - (1<<l)+1][l]) << endl;
    }
    
    return 0;
}
