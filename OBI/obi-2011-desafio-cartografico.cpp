// 21/10/20 // 5:35 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair

const int MAXN = (1e6) + 10;

vector<int> grafo[MAXN];

pair<int, int> dfs(int u, int ant){ // {distancia, vertice}

    pair<int, int> resp = mp(0, u);

    for(int v: grafo[u]){
        if(v==ant) continue;

        pair<int, int> temp = dfs(v, u);
        temp.first++;

        if(temp.first>resp.first){
            resp = temp;
        }
    }

    return resp;
}


int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    cout << dfs(dfs(1, -1).second, -1).first << endl;

    return 0;
}
