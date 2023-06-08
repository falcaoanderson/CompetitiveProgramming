// 08/06/23 //
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

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

//const int INF  = 0x3f3f3f3f;
//const int MAXN = (1e6) + 5;
//const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, m;
    
    while(cin >> n >> m){
        if(n==0) break;
        map<pii, int> pos;
        unordered_map<int, int> last;

        for(int i=1; i<=n; i++){
            int val;
            cin >> val;

            if(last.find(val)!=last.end()) last[val]++;
            else last[val] = 1;

            pos[pii(val, last[val])] = i;
        }

        while(m--){
            int k, val;
            cin >> k >> val;

            if(pos.find(pii(val, k))!=pos.end()){
                cout << pos[pii(val, k)] << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }

    return 0;
}