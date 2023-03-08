// 21/01/19 // 11:29 PM //

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 10010

int m, n, maior_peso=-1;
int peso[MAXN];
int visitado[MAXN];
int qnt_peso[MAXN];
int presente_peso[MAXN];

vector<int> v[MAXN];

void DFS(int x, int d){
    if(d > maior_peso) maior_peso=d;

    visitado[x] = 1;
    peso[x]     = d;
    qnt_peso[d]+= 1;

    d++;
    for(int i=0; i<v[x].size(); i++){
        int temp = v[x][i];

        if(!visitado[temp])
            DFS(temp, d);
    }

}

int main(){
    cin >> m >> n;

    for(int i=1; i<=m; i++){
        int a;
        cin >> a;
        v[a].push_back(i);
    }

    DFS(0,0);

    for(int i=0; i<n; i++){
        int a, temp;

        cin >> a;
        temp = peso[a];

        presente_peso[temp]++;
    }

    cout.precision(2);
    cout.setf(ios::fixed);

    for(int i=1; i<=maior_peso; i++){
        float num1, num2;
        num1 = presente_peso[i]*100;
        num2 = qnt_peso[i];

        cout << num1/num2 << " ";
    }
    cout << "\n";

    return 0;
}
