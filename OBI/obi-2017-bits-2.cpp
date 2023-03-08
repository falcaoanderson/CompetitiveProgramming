// 22/03/2019 // 9:17 AM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1010
#define RESTO 1000000007

int n, k;
int memo[MAXN][MAXN];

int funcao(int i, int qnt){
    if(memo[i][qnt]>-1) return memo[i][qnt];

    if(i>n) return memo[i][qnt]=1;

    int zero=0, um=0;

    zero = (funcao(i+1, 0)) % RESTO;

    if(qnt<k-1)
        um = (funcao(i+1, qnt+1)) % RESTO;

    return memo[i][qnt] = (zero + um) % RESTO;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin >> n >> k;

    cout << funcao(1,0) << "\n";

    return 0;
}
