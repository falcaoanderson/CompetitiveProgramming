// 30/12/19 // 01:26 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 10;

int n, m;
vector<int> grafo[MAXN];
int memo[MAXN];

int solve(int no){
    if(memo[no]!=-1) return memo[no];

    memo[no] = 0;
    for(int adj : grafo[no]){
        memo[no] = max(memo[no], 1 + solve(adj));
    }

    return memo[no];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].pb(b);
    }

    int resp = 0;
    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++)
        if(memo[i]==-1)
            resp = max(resp, solve(i));

    cout << resp << endl;

    return 0;
}
