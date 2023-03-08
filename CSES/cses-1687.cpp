// 20/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ll long long

const int MAXN = (2e5) + 10;

int n, q;
int anc[MAXN][30];

int ancestor(int u, int k){
    if(k==1) return anc[u][0];

    if(k==(k&-k)){
        for(int i=0; i<20; i++)
            if(1<<i == k) return anc[u][i];
    }

    return ancestor(ancestor(u, (k&-k)), k-(k&-k));
}

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=2; i<=n; i++) cin >> anc[i][0];
    
    for(int i=2; i<=n; i++)
        for(int k=1; k<20; k++)
            anc[i][k] = anc[anc[i][k-1]][k-1];

    while(q--){
        int u, k;
        cin >> u >> k;

        int r = ancestor(u, k);

        if(r==0) cout << -1 << endl;
        else     cout << r << endl;
    }

    return 0;
}
