// 20/01/19 // 8:25 PM //

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1010

int n, m, grupo[MAXN]; // 0 = sem grupo / 1 = com grupo //
vector<int> v[MAXN];

void DFS(int x){

    for(int i=0; i<v[x].size(); i++){
        int tv=v[x][i];

        if(grupo[tv]==0){
            grupo[tv]=-1;
            DFS(tv);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int conexas=0;
    for(int i=1; i<=n; i++){
        if(grupo[i]==0){
            conexas++;
            DFS(i);
        }
    }
    cout << conexas << "\n";

    return 0;
}

