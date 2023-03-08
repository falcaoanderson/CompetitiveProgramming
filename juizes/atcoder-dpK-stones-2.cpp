// 26/01/20 // 10:06 AM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(1e2) + 10;
const int MAXK = (int)(1e5) + 10;

int n, k;
int a[MAXN], memo[MAXK];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];

    for(int h=1; h<=k; h++)
        for(int i=0; i<n && a[i]<=h && !memo[h]; i++)
            memo[h] = !memo[h-a[i]];

    cout << (memo[k]?"First\n":"Second\n");

    return 0;
}

