// 21/01/19 // 6:25 PM //
// 22/01/19 // 1:26 PM //

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 510

int n, m, p, jovem;
int idade[MAXN], real[MAXN], visitado[MAXN];
vector<int> v[MAXN];


void DFS(int x){

    visitado[x]=1;

    for(int i=0; i<v[x].size(); i++){
        int temp = v[x][i];

        if(!visitado[temp]){
            jovem = min(jovem, idade[temp]);
            DFS(temp);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m >> p){

        for(int i=1; i<=n; i++){
            cin >> idade[i];
            real[i] = i;
            v[i].clear();
        }

        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            v[b].push_back(a); // b eh gerenciado por a
        }

        for(int i=0; i<p; i++){
            char o;
            int a, b;

            cin >> o;

            if(o=='T'){
                cin >> a >> b;

                swap(real[a], real[b]);

                a = real[a];
                b = real[b];

                swap(idade[a], idade[b]);
            }
            else{
                cin >> a;

                a = real[a];
                jovem = 110;
                memset(visitado, 0, sizeof(visitado));
                DFS(a);

                if(jovem==110) cout << "*\n";
                else cout << jovem << "\n";
            }
        }

    }

    return 0;
}
