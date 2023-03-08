// 04/09/19 // 8:20 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010

int n, v[MAXN];
long long memo[6][6];

void solve(){

    memset(memo, 0, sizeof(memo));

    for(int l=n+1; l>=2; l--){
        for(int r=2; r<=n+1; r++){

            if(l>r) memo[l%3 +2][r%3 + 2] = 0;
            else
                memo[l%3+2][r%3 + 2] = max(v[l] + min(memo[(l+2)%3+2][ r%3 + 2], memo[(l+1)%3 +2][(r-1)%3 + 2]),
                                 v[r] + min(memo[(l+1)%3 +2][(r-1)%3 +2], memo[l%3 +2][(r-2)%3 +2]));
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n && n!=0){

        for(int i=2; i<=n+1; i++){
            cin >> v[i];
        }

        solve();

        /*
        for(int i=2; i<=4; i++){
            for(int j=2; j<=4; j++){
                cout << memo[i][j] << " ";
            }
            cout << "\n";
        }
        */

        cout << memo[4][(n+1)%3 +2] << "\n";
    }

    return 0;
}
