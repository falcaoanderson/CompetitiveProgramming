#include <bits/stdc++.h>

using namespace std;


bool diagonal_a[20], diagonal_b[20], coluna[20];
char ma[20][20];

int solve(int i){
    int total = 0;

    if(i==9) return 1;

    for(int j=1; j<=8; j++){
        if(!diagonal_a[7+i-j] && !diagonal_b[i+j-2] && !coluna[j] && ma[i][j]!='*'){

            diagonal_a[7+i-j] = diagonal_b[i+j-2] = coluna[j] = 1;
            total += solve(i+1);
            diagonal_a[7+i-j] = diagonal_b[i+j-2] = coluna[j] = 0;
        }
    }


    return total;
}

int main(){

    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cin >> ma[i][j];
        }
    }

    cout << solve(1) << endl;

    return 0;
}
