// 07/06/20 // 9:03 PM //

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)(2e5) + 10;
int n, v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    sort(v+1, v+n+1);

    int cont = 1;
    for(int i=2; i<=n; i++) if(v[i]!=v[i-1])cont++;

    cout << cont << endl;

    return 0;
}
