// 11/06/2020 // 10:07 PM //

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int MAXN = 510;
const int INF  = 0x3f3f3f3f;

int n, m, k;
int idade[MAXN], pos[MAXN];
bool visitado[MAXN];
vector<int> grafo[MAXN];

int dfs(int no){
    int auxMin = INF;
    visitado[no] = 1;

    for(int adj: grafo[no])
        if(!visitado[adj])
            auxMin = min(min(auxMin, idade[adj]), dfs(adj));

    return auxMin;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        cin >> idade[i];
        pos[i] = i;
    }

    while(m--){
        int x, y;
        cin >> x >> y;

        grafo[y].pb(x);
    }

    while(k--){
        char op;
        int a, b;
        cin >> op;

        if(op=='T'){
            cin >> a >> b;

            swap(idade[pos[a]], idade[pos[b]]);
            swap(pos[a], pos[b]);
        }
        else{
            cin >> a;

            memset(visitado, 0, sizeof(visitado));
            int resp = dfs(pos[a]);

            if(resp==INF) cout << "*" << endl;
            else          cout << resp << endl;
        }
    }

    return 0;
}
