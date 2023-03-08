// 17/12/19 // 5:10 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 10;

int n, m;
int grau[MAXN], visitado[MAXN];
vector<int> grafo[MAXN];

int dfs(int no){
    visitado[no] = 1;

    int qnt_impar = 0;

    if(grau[no]&1) qnt_impar++;

    for(int adj : grafo[no])
        if(!visitado[adj])
            qnt_impar += dfs(adj);

    return qnt_impar;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;

        grafo[x].pb(y);
        grafo[y].pb(x);
        grau[x]++; grau[y]++;
    }

    int resp = 0;

    for(int i=1; i<=n; i++)
        if(!visitado[i]){
            int temp = dfs(i)/2;
            resp += temp==0? 1: temp;
        }


    cout << (resp - 1) << endl;

    return 0;
}
