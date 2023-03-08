// 12/06/20 // 7:03 PM //

#include<bits/stdc++.h>

using namespace std;

const int MAXN = (int)(1e5) + 10;
int n, k, dist[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<n; i++) cin >> dist[i];

    sort(dist, dist+n);

    int resp = 0x3f3f3f3f;
    for(int i=0; i<k+1; i++)
        resp = min(resp, dist[i+(n-k-1)]-dist[i]);

    cout << resp << endl;

    return 0;

}
