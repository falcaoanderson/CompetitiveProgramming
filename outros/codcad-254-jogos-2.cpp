// 03/09/19 // 6:07 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define INF 0x3f3f3f3f

int n, v[MAXN], total=0;
int memo[MAXN][MAXN];

void solve(){

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        total += v[i];
    }

    solve();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }

    int temp = memo[1][n];
    int temp2 = total - temp;
    if(temp<temp2) swap(temp, temp2);
    cout << temp << " " << temp2 << "\n";

    return 0;
}

