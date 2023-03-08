// 10/06/19 // 10:03 AM //

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 100010

int n;
int h[MAXN];
int memo[MAXN];

int funcao(int i){
    if(memo[i]>=0) return memo[i];

    if(i>=n) return 0;

    if(i==n-1)
        return memo[i] = abs(h[i]-h[i+1]);

    return memo[i] = min(abs(h[i]-h[i+1])+funcao(i+1),abs(h[i]-h[i+2]) + funcao(i+2));
}

int main(){

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for(int i=1; i<=n; i++) cin >> h[i];

    cout << funcao(1) << "\n";

    return 0;
}
