// 07/09/23 //
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

void solve(){
    int n;
    cin >> n;

    int last = -1;
    vector<int> seq;

    while(n--){
        int crr;
        cin >> crr;

        if(crr>=last){
            seq.PB(crr);
        }
        else{
            seq.PB(crr);
            seq.PB(crr);
        }

        last = crr;
    }
    
    cout << seq.size() << endl;
    for(int i: seq) cout << i << " ";
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
