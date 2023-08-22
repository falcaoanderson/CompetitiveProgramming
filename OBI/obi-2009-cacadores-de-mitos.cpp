// 22/08/23 //
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

const int MAXN = (5e2) + 5;

bool grid[MAXN][MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;

    bool resp = 0;

    while(n--){
        int x, y;
        cin >> x >> y;

        if(grid[x][y]) resp=1;

        grid[x][y] = 1;
    }

    cout << resp << endl;

    return 0;
}
