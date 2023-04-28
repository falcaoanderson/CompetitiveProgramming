// 28/04/23 // dp iterativa // O(n * 2^(2m)) // toma TLE, pq?
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    if(n<m) swap(n, m);

    //memo[i][mask] = quantidade de formas de preecher o grid 'i x m' onde a mascara de bits 'mask' representa a linha 'i-1'
    
    memo[n][0] = 1;
    for(int i=n-1; i>=0; i--){
        for(int mask=0; mask<(1<<m); mask++){
            
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

                memo[i][mask] = (memo[i][mask] + memo[i+1][j])%MOD;
            }            

        }
    }

    cout << memo[0][0] << endl;

    return 0;
}