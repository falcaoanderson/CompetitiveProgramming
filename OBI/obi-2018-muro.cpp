// 29/05/19 // 7:58 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 10010
#define MOD 1000000007

int n;
long long memo[MAXN][3];

long long funcao(int i, int tipo){

    if(memo[i][tipo]>=0) return memo[i][tipo];

    if(i==n+1) return memo[i][tipo]=1LL;

    if(i>n) return 0LL;

    int temp = 0;

    if(tipo==1){
        temp = (temp + (funcao(i+1, 1))%MOD)%MOD;

        if(i<n)
            temp = (temp + (2*funcao(i+2, 1))%MOD + (2*funcao(i+1,2))%MOD)%MOD;
    }
    else if(tipo==2){
        temp = (temp + (funcao(i+1, 1))%MOD)%MOD;

        if(i<n)
            temp = (temp + (funcao(i+2, 1))%MOD)%MOD;
    }

    return memo[i][tipo] = (temp)%MOD;
}

int main(){

    memset(memo, -1, sizeof(memo));

    cin >> n;

    cout << funcao(1,1) << "\n";

    return 0;
}
