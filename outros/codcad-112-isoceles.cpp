// 15/12/19 // 10:44 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int MAXN = 5e4 + 10;

int n, h[MAXN];
int prefix[MAXN], sufix[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) cin >> h[i];

    for(int i=1; i<=n; i++) prefix[i] = min(h[i], prefix[i-1] + 1);
    for(int i=n; i>=1; i--) sufix[i]  = min(h[i], sufix[i+1]  + 1);

    int resp = 1;
    for(int i=1; i<=n; i++)
        resp = max(resp, min(prefix[i], sufix[i]));

    cout << resp << endl;

    return 0;
}
