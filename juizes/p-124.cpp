#include <iostream>
using namespace std;
#define MAXN 1005

int x[8]={-1,-1,-1,0,1,1, 1, 0};
int y[8]={-1, 0, 1,1,1,0,-1,-1};
int m, n;
char matriz[MAXN][MAXN];

bool borda(int a, int b){
    if(a>=0 and a<m and b>=0 and b<n){
        return true;
    }
    return false;
}

int bombas(int i, int j){
    int bomba = 0;
    int new_i,new_j;

    for(int c=0; c<8; c++){
        new_i = i + x[c];
        new_j = j + y[c];
        if(borda(new_i,new_j) and matriz[new_i][new_j]=='*'){
            bomba++;
        }
    }
    return bomba;
}


int main(){
    int cont =1;
    while(true){
        cin >> m >> n;
        if(m==0 and n==0){break;}

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> matriz[i][j];
            }
        }

        cout << "Field #" << cont << ":" << endl;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matriz[i][j]=='*'){cout << '*';}
                else{cout << bombas(i,j);}
            }
            cout << endl;
        }
        cout << endl;
        cont ++;
    }

    return 0;
}
