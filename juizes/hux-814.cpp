// 05/08/19 // 5:36 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXP 10

int n;
int qnt_pecas[MAXP];

bool peca[MAXP][MAXP];
bool visitado[MAXP][MAXP];

void DFS(int x, int y){
    visitado[x][y] = visitado[y][x] = 1;

    for(int i=0; i<7; i++){
        if(peca[x][i] && !visitado[x][i])
            DFS(x,i);
        if(peca[y][i] && !visitado[y][i])
            DFS(y,i);
    }
}

bool conexo(){
    int x, y;

    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++)
            if(peca[i][j]){
                x=i;
                y=j;
                i=7;
                break;
            }

    DFS(x,y);

    for(int i=0; i<7; i++)
        for(int j=0; j<7; j++)
            if(peca[i][j] && !visitado[i][j])
                return 0;

    return 1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cont=1;

    cin >> n;
    while(n){

        memset(peca, 0, sizeof(peca));
        memset(qnt_pecas, 0, sizeof(qnt_pecas));
        memset(visitado, 0, sizeof(visitado));

        cout << "Teste " << cont++ << "\n";

        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            qnt_pecas[x]++;
            qnt_pecas[y]++;

            peca[x][y] = peca[y][x] = 1;
        }

        int qnt_impar=0;
        for(int i=0; i<7; i++)
            if( (qnt_pecas[i]%2)==1 ) qnt_impar++;

        if(conexo() && (qnt_impar==0 || qnt_impar==2))
            cout << "sim\n\n";
        else
            cout << "nao\n\n";

        cin >> n;
    }

    return 0;
}

