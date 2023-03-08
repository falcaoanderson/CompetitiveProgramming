// 30/05/20 // 5:04 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = 110;

int n, m;
int cor[MAXN];
vector<int> graph[MAXN];
bool visitado[MAXN];

bool dfs(int no, int dest, int ncor){
    visitado[no] = true;

    if(no == dest){
        cor[no] = ncor;
        return true;
    }

    bool aux = false;

    for(int v : graph[no]){
        if(!visitado[v]) aux |= dfs(v, dest, ncor);
    }

    if(aux){
        cor[no] = ncor;
        return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        graph[a].pb(b);
        graph[b].pb(a);
    }

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        memset(visitado, 0, sizeof(visitado));
        dfs(a, b, c);
    }

    for(int i=1; i<=n; i++)
        cout << cor[i] << " ";
    cout << endl;

    return 0;
}
