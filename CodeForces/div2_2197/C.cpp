/*
11/02/26 

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

// int grid[100][100][5];

int main(){
    fast_io;

    // for(int p = 1; p < 20; p++){
    //     for(int q = 2; q < 20; q++){
    //         if(p*3 == q*2){
    //             grid[p][q][0] = grid[p][q][1] = 1;
    //         }
    //         else{
    //             grid[p][q][0] = min(grid[p-1][q][1], grid[p][q-1][1]);
    //             grid[p][q][1] = max(grid[p-1][q][0], grid[p][q-1][0]);
    //         }

    //         cout << (grid[p][q][0]?'B':'A') << " ";
    //     }
    //     cout << endl;
    // }
    
    int t;
    cin >> t;
    while(t--){
        ll p, q;
        cin >> p >> q;

        if(q-p >= 1 && 3LL*p-2LL*q >= 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }

    return 0;
}
