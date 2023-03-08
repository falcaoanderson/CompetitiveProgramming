// 13/04/20 // 19:13 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = (int)(1e5) + 10;
const int INF  = 0x3f3f3f3f;

int n;
vector<int> grafo[MAXN], ordem;
int pai[MAXN], level[MAXN], menor[MAXN];

bool ord(int a, int b){
    return level[a] > level[b];
}

void DFS(int no){
    for(int adj : grafo[no]){
        if(pai[adj] != 0) continue;

        pai[adj]   = no;
        level[adj] = level[no] + 1;

        DFS(adj);
    }
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

    pai[1]   = 1;
    level[1] = 0;
    DFS(1);

    for(int i=1; i<=n; i++) ordem.pb(i);
    sort(ordem.begin(), ordem.end(), ord);

    int resp = INF;

    for(int p : ordem){

        menor[p] = INF;

        for(int v: grafo[p]){
            if(level[v] < level[p]) continue;

            if(menor[p]!=INF) resp = min(resp, menor[p]+menor[v]-2*level[p]);

            if(menor[p] > menor[v]) menor[p] = menor[v];
        }

        if(menor[p] == INF) menor[p] = level[p];

        //printf("menor[%d] = %d\n", p, menor[p]);
    }

    if((int)grafo[1].size()==1) resp = min(resp, menor[1]);

    cout << resp << endl;

    return 0;
}
