// 26/07/23 //
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

const int MAXN = (1e6) + 5;

int memo[MAXN][5];

int main(){
    fast_io;

    int n, m;
    while(cin >> n >> m){
        vector<int> v(m);
        for(int i=0; i<m; i++) cin >> v[i];

        memo[0][0] = 1;
        memo[0][1] = 0;

        for(int i=1; i<=n; i++){
            for(int j=0; j<2; j++){

                if(j) memo[i][j] = -1;
                else  memo[i][j] = 2;

                for(int k=0; k<m; k++){
                    if(j==1 && i>=v[k]) memo[i][j] = max(memo[i][j], memo[i-v[k]][j^1]);
                    if(j==0 && i>=v[k]) memo[i][j] = min(memo[i][j], memo[i-v[k]][j^1]); 
                }
            }
        }

        cout << (memo[n][0]==0? "Stan": "Ollie") << " wins" << endl;
    }

    return 0;
}
