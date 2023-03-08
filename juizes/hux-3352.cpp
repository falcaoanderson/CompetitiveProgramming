// 29/09/20 // 7:47 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = (1e3) + 10;

vector<int> grafo[MAXN];
bool visitado[MAXN];

int dfs(int no){
    visitado[no] = 1;

    priority_queue<int> ordem;

    for(int v: grafo[no]){
        if(!visitado[v]) ordem.push(dfs(v));
    }

    int t=1, custo=0;
    while(!ordem.empty()){
        custo = max(custo, ordem.top() + t);

        t++;
        ordem.pop();
    }

    return custo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, r;
        cin >> n >> r;
        for(int i=1; i<=n; i++) grafo[i].clear();

        for(int i=1; i<n; i++){
            int a, b;
            cin >> a >> b;

            grafo[a].pb(b);
            grafo[b].pb(a);
        }

        memset(visitado, 0, sizeof(visitado));

        cout << dfs(r) << endl;
    }

    return 0;
}
