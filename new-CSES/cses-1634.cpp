// 12/04/23 // solucao recursiva
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

const int MAXVAL = 1e6+10;
const int MAXN = 1e2+10;

int n, x, coins[MAXN]; 
int memo[MAXVAL];

int solve(int val){
    if(memo[val]!=-1) return memo[val];

    if(val==0) return memo[val] = 0;

    int resp = MAXVAL;

    for(int i=1; i<=n; i++){
        if(val>=coins[i]) resp = min(resp, 1+solve(val-coins[i]));
    }

    return memo[val] = resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> x;

    for(int i=1; i<=n; i++){
        cin >> coins[i];
    } 

    memset(memo, -1, sizeof(memo));

    int resp = solve(x);
    cout << (resp<MAXVAL? resp: -1) << endl;
 
    return 0;
}