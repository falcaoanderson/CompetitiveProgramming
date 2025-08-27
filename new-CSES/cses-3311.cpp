/*
22/08/25 

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
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

char grid[MAXN][MAXN];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int k=0; k<=m+n-2; k++){

        int ini_i = max(0, k-m+1);
        int ini_j = min(k, m-1);

        for(int i=ini_i, j=ini_j; i<n && j>=0; i++, j--){
            vector<bool> marked(4);
            marked[grid[i][j]-'A'] = 1;
            if(i>0) marked[grid[i-1][j]-'A'] = 1;
            if(j>0) marked[grid[i][j-1]-'A'] = 1;

            for(int z=0; z<4; z++){
                if(!marked[z]){
                    grid[i][j] = char(65+z);
                    break;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
