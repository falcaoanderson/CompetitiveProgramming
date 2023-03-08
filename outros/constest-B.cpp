#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

int const MAXN = 5e2 + 10;

int n, m;
vector<int> grafo[MAXN];
bool morreu[MAXN];
bool visitado[MAXN];

int dfs(int no){
    int tam = morreu[no]? 0: 1;
    visitado[no] = 1;

    for(int adj : grafo[no])
        if(!visitado[adj])
            tam += dfs(adj);

    return tam;
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
        grafo[b].pb(a);
    }

    int qnt;
    cin >> qnt;

    for(int i=0; i<qnt; i++){
        int temp;
        cin >> temp;

        morreu[temp]=1;
    }

    vector<int> familia;

    for(int i=1; i<=n; i++)
        if(!visitado[i]){
            int temp = dfs(i);

            if(temp>0) familia.pb(temp);
        }


    sort(familia.begin(), familia.end());

    cout << "Quantidade de familias: " << familia.size() << endl;
    cout << "Numero de habitantes em cada: ";

    cout << familia[0];
    for(int i=1; i<=(int)familia.size()-2; i++){
        cout << ", " << familia[i];
    }
    if(familia.size()>1)
        cout << " e " << familia[familia.size()-1];
    cout << endl;

    return 0;
}
