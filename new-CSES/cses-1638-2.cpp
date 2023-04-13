// 13/04/23 // solucao iterativa com otimizacao de memoria
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
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int MOD = 1e9+7;
const int MAXN = 1e3+5;

int solve[5][MAXN];
char grid[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> grid[i][j];
        }
    }
    
    solve[0][1] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(grid[i][j]=='*') solve[i%2][j] = 0;
            else solve[i%2][j] = (solve[(i-1)%2][j] + solve[i%2][j-1])%MOD;
        }
    }
    
    cout << solve[n%2][n] << endl;
 
    return 0;
}