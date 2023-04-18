// 18/04/23 // dp iterativa
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
 
const int MAXN = 5e2+5;

int solve[MAXN][MAXN]; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i>j && i<=b){
                solve[i][j] = solve[j][i];
                continue;
            }
            if(i==j) continue;

            solve[i][j] = a*b+1;
            
            for(int x=1; 2*x<=i; x++){
                solve[i][j] = min(solve[i][j], 1 + solve[x][j] + solve[i-x][j]);
            }
            for(int x=1; 2*x<=j; x++){
                solve[i][j] = min(solve[i][j], 1 + solve[i][x] + solve[i][j-x]);
            }
        }
    }

    cout << solve[a][b] << endl;

    return 0;
}