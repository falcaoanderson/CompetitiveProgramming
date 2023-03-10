// 06/12/19 // 2:32 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 50010
#define MAXLOG 20
#define pb push_back

int n;
int nivel[MAXN], ancestral[MAXN][MAXLOG];

pair<int, int> pcarta[MAXN];
vector<int> grafo[MAXN];

void dfs(int no){

    for(int filho : grafo[no]){
        if(nivel[filho] == -1){

            ancestral[filho][0] = no;
            nivel[filho]        = nivel[no] + 1;

            dfs(filho);
        }
    }
}

void ini_nivel_e_ancestral(){
    memset( ancestral, -1, sizeof(ancestral));
    memset(     nivel, -1, sizeof(  nivel  ));
    nivel[1]         = 0;
    ancestral[1][0]   = 1;

    dfs(1);

    for(int j=1; j<MAXLOG; j++)
        for(int i=1; i<=n; i++)
            if(ancestral[i][j-1] != -1)
                ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];

}

int lca(int u, int v){

    if(nivel[v] > nivel[u]) swap(u, v);

    for(int i=MAXLOG-1; i>=0; i--)
        if(nivel[ ancestral[u][i] ] >= nivel[v])
            u = ancestral[u][i];

    if(u==v) return u;

    for(int i=MAXLOG-1; i>=0; i--)
        if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return ancestral[u][0];
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;

        if(pcarta[temp].first == 0) pcarta[temp].first  = i;
        else                        pcarta[temp].second = i;
    }

    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;
        grafo[x].pb(y);
        grafo[y].pb(x);
    }

    ini_nivel_e_ancestral();

    long long resp = 0;
    for(int i=1; i<=n/2; i++){
        int ca = pcarta[i].first;
        int cb = pcarta[i].second;

        int mac = lca(ca, cb);

        resp += (nivel[ ca ] + nivel[ cb ] - 2*nivel[mac]);
    }

    cout << resp << "\n";


    /*
    for(int i=1; i<=n; i++){
        cout << "vertice: "<< i << "\n";
        cout << nivel[i] << "\n";

        for(int j=0; j<4; j++){
            cout << ancestral[i][j] << " ";
        }
        cout << "\n";
    }
    */
    return 0;
}