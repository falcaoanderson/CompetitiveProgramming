// 15/11/19 // 10:29 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 300010
#define ll long long

int n, v[MAXN];
ll s, val;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    for(int i=1; i<=n; i++) cin >> v[i];

    sort(v+1, v+n+1);

    for(int i=1; i<=n; i++){
        if(v[i]-v[i-1]<s && i!=1)val += v[i]-v[i-1];
        else val += s;
    }

    cout << val << "\n";

    return 0;
}
