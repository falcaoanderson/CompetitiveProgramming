// 22/02/19 // 8:47 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1010

int n, k;
int memo[MAXN][MAXN];

int funcao(int i, int anter){
    if(memo[i][anter]>=0) return memo[i][anter];

    if(i>n)
        return memo[i][anter] = 1;


    if(anter<k-1)
        return memo[i][anter] = (funcao(i+1, 0) + funcao(i+1,anter+1))%(1000000007);

    return memo[i][anter] = funcao(i+1, 0)%(1000000007);
}

int main(){
    cin >> n >> k;

    memset(memo, -1, sizeof(memo));

    cout << funcao(1,0)%(1000000007) << "\n";

    return 0;
}
