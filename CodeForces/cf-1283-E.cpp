/*
11/01/24 
Problem: 
Complexity:
*/

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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n,  val[MAXN];
int memo[MAXN][10];

int calc_op(int a, int b){ // a<=b
    if(a<b-1){
        return 0;
    }
    if(a==b-1){
        return 1;
    }
    if(a==b){
        return 2;
    }
    return 3;
}
int min(int a, int b, int c){
    return min(a, min(b, c));
}
int max(int a, int b, int c){
    return max(a, max(b, c));
}

int solve(int i, int op){
    if(memo[i][op]!=-1) return memo[i][op];

    if(i>n) return 0;

    if(op==0){     // anterior < val[i]-1
        int aux1 = 1 + solve(i+1, calc_op(val[i]-1, val[i+1]));
        int aux2 = 1 + solve(i+1, calc_op(  val[i], val[i+1]));  
        int aux3 = 1 + solve(i+1, calc_op(val[i]+1, val[i+1]));
        memo[i][op] = max(aux1, aux2, aux3);  
    }
    else if(op==1){// anterior == val[i]-1
        int aux1 = 0 + solve(i+1, calc_op(val[i]-1, val[i+1]));
        int aux2 = 1 + solve(i+1, calc_op(  val[i], val[i+1]));  
        int aux3 = 1 + solve(i+1, calc_op(val[i]+1, val[i+1]));
        memo[i][op] = max(aux1, aux2, aux3); 
    }
    else if(op==2){// anterior == val[i]
        int aux2 = 0 + solve(i+1, calc_op(  val[i], val[i+1]));  
        int aux3 = 1 + solve(i+1, calc_op(val[i]+1, val[i+1]));
        memo[i][op] = max(aux2, aux3);
    }
    else if(op==3){//anterior == val[i]+1
        memo[i][op] = solve(i+1, calc_op(val[i]+1, val[i+1]));
    }

    return memo[i][op];
}
int solve_min(int i, int op){
    if(memo[i][op]!=-1) return memo[i][op];

    if(i>n) return 0;

    if(op==0){     // anterior < val[i]-1
        int aux1 = 1 + solve_min(i+1, calc_op(val[i]-1, val[i+1]));
        int aux2 = 1 + solve_min(i+1, calc_op(  val[i], val[i+1]));  
        int aux3 = 1 + solve_min(i+1, calc_op(val[i]+1, val[i+1]));
        memo[i][op] = min(aux1, aux2, aux3);  
    }
    else if(op==1){// anterior == val[i]-1
        int aux1 = 0 + solve_min(i+1, calc_op(val[i]-1, val[i+1]));
        int aux2 = 1 + solve_min(i+1, calc_op(  val[i], val[i+1]));  
        int aux3 = 1 + solve_min(i+1, calc_op(val[i]+1, val[i+1]));
        memo[i][op] = min(aux1, aux2, aux3); 
    }
    else if(op==2){// anterior == val[i]
        int aux2 = 0 + solve_min(i+1, calc_op(  val[i], val[i+1]));  
        int aux3 = 1 + solve_min(i+1, calc_op(val[i]+1, val[i+1]));
        memo[i][op] = min(aux2, aux3);
    }
    else if(op==3){//anterior == val[i]+1
        memo[i][op] = solve_min(i+1, calc_op(val[i]+1, val[i+1]));
    }

    return memo[i][op];
}


int main(){
    fast_io;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> val[i];

    sort(val+1, val+n+1);
    
    memset(memo, -1, sizeof(memo));
    cout << solve_min(1, 0) << " ";

    memset(memo, -1, sizeof(memo));
    cout << solve(1, 0) << endl;
    
    return 0;
}
