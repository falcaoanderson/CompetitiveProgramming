// 15/01/2020 // 21:34 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5;

int main(){
    fastio;

    int n, m;

    cin >> n;
    vector<int> prefix(n+1);

    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }
    cin >> m;

    while(m--){
        int q;
        cin >> q;

        cout << lower_bound(prefix.begin(), prefix.end(), q)-prefix.begin() << endl;
    }

    return 0;
}
