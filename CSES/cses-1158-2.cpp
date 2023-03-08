// 01/11/20 // 4:06 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int price[1005], page[1005], memo[100005];

int main(){
    fast_io;

    int n, x;
    cin >> n >> x;

    for(int i=1; i<=n; i++) cin >> price[i];
    for(int i=1; i<=n; i++) cin >> page[i];

    for(int i=1; i<=n; i++)
        for(int j=x; j>=price[i]; j--)
            memo[j] = max(memo[j], memo[j-price[i]] + page[i]); 

    cout << memo[x] << endl;

    return 0;
}
