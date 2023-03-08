// 05/03/2019 // 12:01 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXR 110
#define MAXK 25

int r, k;
int memo[MAXK][MAXR][MAXR];

int funcao(int qnt, int atual, int total){

    if(memo[qnt][atual][total]>=0) return memo[qnt][atual][total];

    if(total==0){
        if(qnt == k) return memo[qnt][atual][total] = 1;
        else         return memo[qnt][atual][total] = 0;
    }

    if( qnt>=k || atual>total) return memo[qnt][atual][total] = 0;

    return memo[qnt][atual][total] = funcao(qnt, atual+1, total) + funcao(qnt+1, atual+1, total-atual);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> r >> k;

    cout << funcao(0, 1, r) << "\n";

    return 0;
}
