// 09/01/20 // 8:36 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 1e3 + 10;
const int MAXX = 1e5 + 10;

int n, x;
int memo[2][MAXX];
int price[MAXN], page[MAXN];

void solve(){

    for(int i=n; i>=1; i--){
        for(int j=1; j<=x; j++){

            memo[i&1][j] = memo[~i&1][j];
            if(price[i]<=j)
                memo[i&1][j] = max(memo[i&1][j], page[i] + memo[~i&1][j-price[i]]);
        }
    }

}

int main(){

    cin >> n >> x;

    for(int i=1; i<=n; i++) cin >> price[i];
    for(int i=1; i<=n; i++) cin >>  page[i];

    solve();

    cout << memo[1][x] << endl;

    return 0;
}
