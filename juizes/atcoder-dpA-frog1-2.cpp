// 14/06/19 // 02:02 AM //

#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 100010

int n;
int h[MAXN];
int memo[MAXN];

int bottom_up(){

    memo[0] = MAXN;

    for(int i=2; i<=n; i++){
        memo[i] = min(memo[i-1]+abs(h[i]-h[i-1]), memo[i-2] + abs(h[i]-h[i-2]) );
    }

    return memo[n];
}

int main(){

    cin >> n;

    for(int i=1; i<=n; i++) cin >> h[i];

    cout << bottom_up() << "\n";

    return 0;
}

