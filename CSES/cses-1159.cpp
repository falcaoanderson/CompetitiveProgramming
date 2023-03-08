// 10/01/20 // 9:29 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back

const int MAXN = 1e3 + 10;
const int MAXX = 1e5 + 10;
const int LOGK = 10;

int n, x;
int memo[2][MAXX];
int copies[MAXN], price[MAXN], pages[MAXN], ind;

void solve(){

    for(int i=ind; i>=1; i--)
        for(int j=1; j<=x; j++){

            memo[i&1][j] = memo[~i&1][j];
            if(price[i]<=j)
                memo[i&1][j] = max(memo[i&1][j], pages[i] + memo[~i&1][j-price[i]]);
        }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    for(int i=1; i<=n; i++) cin >> price[i];
    for(int i=1; i<=n; i++) cin >> pages[i];
    for(int i=1; i<=n; i++) cin >> copies[i];
    ind = n;

    for(int i=1; i<=n; i++){
        int sum = 3, j=2;

        while(sum<=copies[i]){

            ind++;
            price[ind] = j*price[i];
            pages[ind] = j*pages[i];

            j = j<<1;
            sum += j;
        }

        if(sum>copies[i]) sum -= j;

        if(sum<copies[i]){
            ind++;
            price[ind] = (copies[i]-sum)*price[i];
            pages[ind] = (copies[i]-sum)*pages[i];
        }
    }

    solve();
    cout << memo[1&1][x] << endl;
}
