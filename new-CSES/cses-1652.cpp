// 02/05/23 // prefix sum 2d
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

const int MAXN = (1e3) + 5;

int prefix[MAXN][MAXN];

int main(){
    fast_io;

    int n, q;
    cin >> n >> q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char temp;
            cin >> temp;

            prefix[i][j] = prefix[i][j-1] + (int)(temp=='*');
        }

        for(int j=1; j<=n; j++) prefix[i][j] += prefix[i-1][j];
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1] << endl;
    }

    return 0;
}
