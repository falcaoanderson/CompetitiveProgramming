#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int n, v[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];

    sort(v+1, v+n+1);
    
    int total=0;

    for(int i=n; i>=1; i-=3){
        total += v[i] + v[i-1];
    }

    cout << total << endl;

    return 0;
}