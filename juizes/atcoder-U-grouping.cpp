// 16/06/19 // 4:18 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 30
#define MAXK 131072 // 1<<17

int n;
int a[MAXN][MAXN];
long long memo[MAXK];

long long max(long long a, long long b, long long c){
    return max(a, max(b, c));
}

long long funcao(int i, int included, int group){
    if (memo[included]>=0) return memo[included];

    if(i>n) return memo[included]=0LL;

    long long  add_group=0LL;

    if( (included&(1<<(i-1)))==0 ){
        for(int j=1; j<=n; j++)
            if( (group&(1<<(j-1)))!=0 )
                add_group += a[i][j];

        return memo[included] = max(add_group + funcao(i+1, included|(1<<i-1), (group|(1<<i-1))),
                                    funcao(i+1, included|(1<<(i-1)), group)+
                                    funcao(i+1, included|(1<<(i-1)),(1<<i-1)));
    }

    return memo[included] = funcao(i+1, included, group);
}

int main(){

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];

    cout << funcao(1, 0, 0) << "\n";

    return 0;
}
