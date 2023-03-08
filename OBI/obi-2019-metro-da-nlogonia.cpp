// 22/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int MAXN = (1e5) + 10;

int n, m, grauC[MAXN], grauQ[MAXN];
vector<int> adjC[MAXN], adjQ[MAXN];
vector<int> centerC, centerQ;

void find_centerC(){
    queue<int> fila;

    for(int i=1; i<=n; i++){
        if(grauC[i]==1){
            fila.push(i);
            grauC[i]--;
        }
    }

    int maxlvl = 0;
    vector<int> lvl(n+1, 0);

    while(!fila.empty()){
        int u = fila.front(); fila.pop();

        for(int v: adjC[u]){
            grauC[v]--;

            if(grauC[v]==1){
                fila.push(v);
                lvl[v] = lvl[u] + 1;
                maxlvl = max(maxlvl, lvl[v]);
            }
        }
    }

    for(int i=1; i<=n; i++)
        if(lvl[i]==maxlvl) centerC.pb(i);
}

void find_centerQ(){
    queue<int> fila;
    
    for(int i=1; i<=m; i++){
        if(grauQ[i]==1){
            fila.push(i);
            grauQ[i]--;
        }
    }

    int maxlvl = 0;
    vector<int> lvl(m+1, 0);

    while(!fila.empty()){
        int u = fila.front(); fila.pop();

        for(int v: adjQ[u]){
            grauQ[v]--;

            if(grauQ[v]==1){
                fila.push(v);
                lvl[v] = lvl[u] + 1;
                maxlvl = max(maxlvl, lvl[v]);
            }
        }
    }

    for(int i=1; i<=m; i++)
        if(lvl[i]==maxlvl) centerQ.pb(i);
}

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;

        adjC[a].pb(b); adjC[b].pb(a);
        grauC[a]++; grauC[b]++;
    }
    for(int i=1; i<=m-1; i++){
        int a, b;
        cin >> a >> b;

        adjQ[a].pb(b); adjQ[b].pb(a);
        grauQ[a]++; grauQ[b]++;
    }

    find_centerC();
    find_centerQ();

    cout << centerC.back() << " " << centerQ.back() << endl;

    return 0;
}
