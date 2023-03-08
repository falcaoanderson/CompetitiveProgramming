// 10/09/19 // 7:26 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define pb push_back
#define INF 0x3f3f3f3f

int n;
int filhos[MAXN];
bool visitado[MAXN];
vector<int> vizinhos[MAXN];

int mdif = INF;

void dfs(int i){

    visitado[i] = 1;
    filhos[i]   = 1;

    for(int j=0; j<vizinhos[i].size(); j++){
        int temp = vizinhos[i][j];

        if(!visitado[temp]){
            dfs(temp);

            filhos[i] += filhos[temp];

            mdif = min(mdif, abs(filhos[temp] - abs(n-filhos[temp])));
        }

    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;

        cin >> a >> b;

        vizinhos[a].pb(b);
        vizinhos[b].pb(a);
    }

    dfs(1);

    cout << mdif << "\n";

    return 0;
}
