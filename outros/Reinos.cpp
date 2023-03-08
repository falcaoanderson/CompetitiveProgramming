// 12/08/19 // 7:07 PM //

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100010
#define PB push_back

int n, m;
int visitado[MAXN];
vector<int> grafo[MAXN];

void DFS(int i){

    visitado[i] = 1;

    for(int j=0; j<grafo[i].size(); j++){
        int temp = grafo[i][j];

        if(!visitado[temp]) DFS(temp);
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].PB(b);
        grafo[b].PB(a);
    }

    int resp=0;

    for(int i=1; i<=n; i++){
        if(!visitado[i]){
            resp++;
            DFS(i);
        }
    }

    cout << resp-1 << "\n";

    return 0;
}
