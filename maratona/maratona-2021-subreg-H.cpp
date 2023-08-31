// 01/08/23 //
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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int vcor[MAXN];
pii block[MAXN];

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> block[i].ff >> block[i].ss;
        vcor[i] = block[i].ss;
    }

    sort(block+1, block+n+1);

    bool flag=true;
    for(int i=1; i<=n; i++){
        flag = flag && (block[i].ss==vcor[i]);
    }

    cout << (flag? "Y": "N") << endl;

    return 0;
}