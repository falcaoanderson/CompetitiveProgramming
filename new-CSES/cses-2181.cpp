// 28/04/23 // dp recursiva // O(n * 2^(2m))
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
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int MAXN = 1e3+5;
const int MAXMASK = (1<<10) + 5;
const int MOD = 1e9+7;

int n, m;
ll memo[MAXN][MAXMASK];

ll solve(int i, int mask){
    if(memo[i][mask]!=-1) return memo[i][mask];

    if(i==n) return memo[i][mask] = (mask==0);

    memo[i][mask] = 0LL;

    for(int j=0; j<(1<<m); j++){
        if((j&mask)!=0) continue;
        
        int temp = mask|j, cont = 0;
        bool flag = true;

        for(int k=0; k<m && flag; k++){
            if((temp&(1<<k)) != 0){
                if(cont&1) flag=false;
                cont = 0;
            }
            else{
                cont++;
            }
        }
        if(!flag || cont&1) continue;

        memo[i][mask] = (memo[i][mask] + solve(i+1, j))%MOD;
    }

    return memo[i][mask];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    if(n<m) swap(n, m);

    //memo[i][mask] = quantidade de formas de preecher o grid 'i x m' onde a mascara de bits 'mask' representa a linha 'i-1'
    
    memset(memo, -1, sizeof(memo));

    cout << solve(0, 0) << endl;

    return 0;
}