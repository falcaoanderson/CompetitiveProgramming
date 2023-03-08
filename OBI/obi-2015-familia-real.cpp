// 27/05/19 // 8:17 PM //

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 10010
#define PB push_back

int n, m, maior_nivel=0;
vector<int> v[MAXN];
bool presente[MAXN];
int nivel[MAXN], qnt_nivel[MAXN], presente_nivel[MAXN];

void BFS(){
    queue<int> fila;

    fila.push(0);

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(int i=0; i<v[atual].size(); i++){
            int temp = v[atual][i];
            nivel[temp] = nivel[atual] + 1;

            qnt_nivel[nivel[temp]]++;
            if(presente[temp]) presente_nivel[nivel[temp]]++;

            maior_nivel = nivel[temp];

            fila.push(temp);
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;

        v[temp].PB(i);
    }

    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;

        presente[temp]=1;
    }

    BFS();

    cout.precision(2);
    cout.setf(ios::fixed);

    for(int i=1; i<=maior_nivel; i++){
        float temp1 = qnt_nivel[i];
        float temp2 = presente_nivel[i];

        temp1 = temp2*100/temp1;

        cout << temp1 << " ";
    }
    cout << "\n";

    return 0;
}
