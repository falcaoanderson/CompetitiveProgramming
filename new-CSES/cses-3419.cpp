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
const int MAXN = (1e2) + 5;
const int MOD  = (1e9) + 7;
 
const int MAXVAL = 2e2;
int grid[MAXN][MAXN];
bool appears[MAXVAL+5];
 
int main(){
    fast_io;
 
    int n;
    cin >> n;
 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            memset(appears, 0, sizeof(appears));
 
            for(int k=i-1; k>=0; k--){
                appears[grid[k][j]] = 1;
            }
            for(int k=j-1; k>=0; k--){
                appears[grid[i][k]] = 1;
            }
 
            for(int k=0; k<=MAXVAL; k++){
                if(!appears[k]){
                    grid[i][j] = k;
                    break;
                }
            }
 
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
 
    return 0;
}