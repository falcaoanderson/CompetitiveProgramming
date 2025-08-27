/*
23/08/25 

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
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n;
int v[MAXN], jump[MAXN];
pii memo[MAXN];

pii solve(int i){
    if(memo[i].FF!=-1) return memo[i];

    if(i>=2*n){
        return {0, 0};
    }

    pii op1 = solve(i+1);
    pii op2 = {0, 0};
    if(jump[v[i]]>i){
        op2 = solve(jump[v[i]] + 1);
        op2.FF += 1;
        op2.SS += jump[v[i]] - i;
    }

    if(op1.FF > op2.FF || (op1.FF==op2.FF && op1.SS<op2.SS)) 
        return memo[i] = op1;
    else
        return memo[i] = op2; 
}

int main(){
    fast_io;

    cin >> n;
    for(int i=0; i<2*n; i++){
        cin >> v[i];

        jump[v[i]] = i;
    }

    for(int i=0; i<2*n; i++){
        memo[i] = {-1, -1};
    }
    pii resp = solve(0);
    cout << resp.FF << " " << resp.SS << endl;

    return 0;
}
