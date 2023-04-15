// 15/04/23 // dp iterativa
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

const int MAXN = 1e5+5;
const int MAXM = 1e2+5;
const int MOD = 1e9+7;
 
int solve[MAXN][MAXM];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    // solve[i][j] de quantas formas eu consigo preencher um lista de tamanho i, onde o ultimo cara da lista eh j

    if(v[1]==0){
        for(int j=1; j<=m; j++) solve[1][j] = 1;
    }
    else{
        solve[1][v[1]] = 1;
    }

    for(int i=2; i<=n; i++){
        if(v[i]!=0){
            solve[i][v[i]] = ((solve[i-1][v[i]-1] + solve[i-1][v[i]])%MOD + solve[i-1][v[i]+1])%MOD;
        }
        else{
            for(int j=1; j<=m; j++){
                solve[i][j] += ((solve[i-1][j-1] + solve[i-1][j])%MOD + solve[i-1][j+1])%MOD;
            }
        }
    }

    int resp = 0;
    for(int j=1; j<=m; j++) resp = (resp + solve[n][j])%MOD;

    cout << resp << endl;
    
    return 0;
}