// 27/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;
const int MOD  = (1e9) + 7;

int szSeq, szN;
string n, seq;
int memo[MAXN];

int solve(int i){
    if(memo[i]!=-1) return memo[i];

    if(i==szSeq) return 1;

    if(seq[i]=='0') return 0;

    memo[i] = 0;

    for(int j=1; j<szN && i+j<=szSeq; j++){
        memo[i] += solve(i+j)%MOD;
        memo[i] %= MOD;
    }

    if(i+szN<=szSeq){
        string temp = seq.substr(i,szN); 
        if(temp<=n){
            memo[i] += solve(i+szN)%MOD;
            memo[i] %= MOD;
        }
    }

    return memo[i];
}

int main(){
    fast_io;

    cin >> n >> seq;

    szSeq = seq.size();
    szN = n.size();

    memset(memo, -1, sizeof(memo));

    cout << solve(0) << endl;

    return 0;
}
