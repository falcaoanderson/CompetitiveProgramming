// 05/03/20 // 08:51 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 1010;
int n, li, ls, v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> li >> ls;

    for(int i=1; i<=n; i++)
        cin >> v[i];

    int cont = 0;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(v[i]+v[j]>= li && v[i]+v[j]<=ls) cont ++;

    cout << cont << endl;

    return 0;
}
