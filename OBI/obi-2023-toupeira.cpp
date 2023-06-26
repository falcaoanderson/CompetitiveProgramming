#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+5;

int s, t;
bool graph[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    for(int i=0; i<t; i++){
        int a, b;
        cin >> a >> b;

        graph[a][b] = graph[b][a] = 1;
    }

    int p;
    cin >> p;
    
    int resp = 0;

    while(p--){
        int tam;
        cin >> tam;

        bool flag=true;

        int u;
        cin >> u;
        for(int i=1; i<tam; i++){
            int v;
            cin >> v;

            if(!flag) continue;

            if(graph[u][v]){
                u = v;
            }
            else{
                flag=false;
            }
        }

        resp += (int)flag;
    }

    cout << resp << endl;

    return 0;
}