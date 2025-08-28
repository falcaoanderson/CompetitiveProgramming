/*
28/08/25 

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

int main(){
    fast_io;

    int n;
    cin >> n;
    
    vector<vector<int>> ma(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c;
            ma[i][j] = (c=='X');
        }
    }

    int resp = 0;
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++){
            resp += ((ma[i][j]+ma[i-1][j-1]+ma[i+1][j-1]+ma[i-1][j+1]+ma[i+1][j+1])==5);
        }
    }
    cout << resp << endl;

    return 0;
}
