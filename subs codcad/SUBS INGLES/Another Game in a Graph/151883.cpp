// 08/12/19 // 4:22 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define INF 0x3f3f3f3f
#define pb push_back

int n, pai[MAXN], peso[MAXN];
int memo[MAXN][5];

vector<int> grafo[MAXN];

int solve(int no, bool pai_colorido){
    if(memo[no][pai_colorido]>-INF) return memo[no][pai_colorido];

    int op1 = peso[no], op2 = 0;

    for(int filho : grafo[no]){
        if(pai[no] == filho) continue;

        pai[filho] = no;

        op1 += solve(filho, 1);
        op2 += solve(filho, 0);
    }

    if(pai_colorido)
        return memo[no][pai_colorido] = op2;
    else
        return memo[no][pai_colorido] = max(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;

        cin >> a >> b;

        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    for(int i=1; i<=n; i++)
        cin >> peso[i];

    for(int i=0; i<MAXN; i++)
        for(int j=0; j<5; j++)
            memo[i][j] = -INF;

    cout << solve(1, 0) << "\n";

    return 0;
}
