// 20/01/19 // 11:52 PM //

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100010

int n, peso[MAXN];
vector<int> v[MAXN];

int DFS(int x){
    if(v[x].size()==0) return 0;

    peso[x] = v[x].size();
    for(int i=0; i<v[x].size(); i++){
        int temp = v[x][i];
        peso[x] += DFS(temp);
    }
    return peso[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    DFS(0);
    int temp, temp2;
    for(int i=1; i<=n; i++){
        if(v[i].size()==1 or v[i].size()==0)continue;
        for(int j=0; j<v[i].size()-1; j++){
            temp = v[i][j];
            temp2= v[i][j+1];
            if(peso[temp]!=peso[temp2]){
                cout << "mal\n";
                return 0;
            }
        }
    }

    cout << "bem\n";

    return 0;
}
