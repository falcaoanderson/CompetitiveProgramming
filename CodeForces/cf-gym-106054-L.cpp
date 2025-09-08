/*
31/08/25 

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define bug(x) cerr << #x << ": " << x << endl

const int MAX = 1e5 + 10;

ll n, g, v[MAX], sp[MAX], dp[MAX][500], raiz, ans;

ll resp(int i, int k){
    return g - sp[i] + sp[i - k];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> g;
    
    int aux=0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(aux + i <= n){
            raiz++;
            aux+=i;
        }
    }

    for(int i = 1; i <= n; i++){
        sp[i] = sp[i - 1] + v[i];
    }

    for(int k = 1; k <= raiz; k++){
        for(int i = 1; i <= n; i++){
            if(i-k>=0)
                dp[i][k] = max(dp[i - k][k - 1] + resp(i, k), dp[i - 1][k]);
            else{
                dp[i][k] = dp[i - 1][k];
            }
        }
    }

    for(int i = 1; i <= raiz; i++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;

}