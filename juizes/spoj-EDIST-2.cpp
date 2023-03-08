// 01/03/19 // 18:36 //

#include <bits/stdc++.h>

using namespace std;

#define MAXL 3000

char u1[MAXL], u2[MAXL];
int tam1, tam2;
int memo[MAXL][MAXL];

int minimo(int x, int y, int z){
    return min(x, min(y,z));
}

int funcao(){

    for(int i=0; i<=tam1; i++){
        for(int j=0; j<=tam2; j++){

            if(i==0)
                memo[i][j] = j;
            else if(j==0)
                memo[i][j] = i;

            else if(u1[i-1]==u2[j-1])
                memo[i][j] = memo[i-1][j-1];
            else
                memo[i][j] = 1 + minimo(memo[i-1][j],
                                        memo[i][j-1],
                                        memo[i-1][j-1]);
        }
    }

    return memo[tam1][tam2];
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++){

        scanf("%s", &u1);
        scanf("%s", &u2);

        tam1 = strlen(u1);
        tam2 = strlen(u2);

        printf("%d\n", funcao());
    }

    return 0;
}

