// 23/01/19 // 8:22 PM //

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXC 1010
#define MAXF 60

int c, f;
int comp[MAXF];
int desc[MAXF];

int memo[MAXF][MAXC];

int funcao(int i, int cap){
    if(memo[i][cap]>=0) return memo[i][cap];

    if(i>f || cap<=0) return memo[i][cap]=0;

    int nao_coloca = funcao(i+1, cap);

    if(cap>=comp[i]){
        int coloca = desc[i] + funcao(i+1, cap-comp[i]);

        return memo[i][cap] = max(coloca, nao_coloca);
    }

    return memo[i][cap] = nao_coloca;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cont = 1;

    while(cin >> c >> f){
        if(c==0 && f==0) break;

        memset(memo, -1, sizeof(memo));

        for(int i=1; i<=f; i++)
            cin >> comp[i] >> desc[i];

        cout << "Teste " << cont << "\n";
        cout << funcao(1, c) << "\n\n";

        cont++;
    }

    return 0;
}
