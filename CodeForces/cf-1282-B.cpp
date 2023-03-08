// 18/01/20 // 1:13 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int MAXN = 2e5 + 10;

int n, p, k;
int v[MAXN], memo[MAXN], prefix[MAXN];

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--){

        cin >> n >> p >> k;
        for(int i=1; i<=n; i++) cin >> v[i];
        sort(v+1, v+n+1);
        for(int i=1; i<k; i++) prefix[i] = prefix[i-1] + v[i];

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(i<k)
                memo[i] = prefix[i];
            else
                memo[i] = v[i] + memo[i-k];

            if(memo[i]<=p) ans = max(ans, i);
        }

        cout << ans << endl;
    }

    return 0;
}
