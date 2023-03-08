// 11/10/20 // 4:28 PM //
// 27/10/20 // 3:40 PM // edit

#include <bits/stdc++.h>
using namespace std;

char caminho[50];
bool visitado[10][10];
int aux_i[5] = {-1, 0, 1,  0, 0}; 
int aux_j[5] = { 0, 1, 0, -1, 0}; 

int solve(int i, int j, int faltam){

    if(i==7 && j==1)
        return (int)(faltam == 0);
    if(faltam == 0) return 0;

    if(visitado[i+1][j] && visitado[i-1][j] && !visitado[i][j-1] && !visitado[i][j+1]) return 0;
    if(visitado[i][j+1] && visitado[i][j-1] && !visitado[i-1][j] && !visitado[i+1][j]) return 0;

    int ans = 0;
    for(int k=0; k<4; k++){
        int new_i = i + aux_i[k];
        int new_j = j + aux_j[k];

        if(caminho[faltam]=='U' && k!=0) continue;
        if(caminho[faltam]=='R' && k!=1) continue;
        if(caminho[faltam]=='D' && k!=2) continue;
        if(caminho[faltam]=='L' && k!=3) continue;

        if(!visitado[new_i][new_j]){
            visitado[new_i][new_j] = 1;
            ans += solve(new_i, new_j, faltam - 1);
            visitado[new_i][new_j] = 0;
        }
    }

    return ans;
}

int main(){
    for(int i=48; i>=1; i--) cin >> caminho[i];
    visitado[1][1] = 1;

    for(int i=0; i<=8; i++){
        visitado[i][0] = visitado[i][8] = 1;
        visitado[0][i] = visitado[8][i] = 1;
    }

    cout << solve(1, 1, 48) << endl;

    return 0;
}

