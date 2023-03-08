// 18/01/20 // 11:28 AM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;

int main(){
    fastio;

    int t;
    cin >> t;

    while(t--){
        int s, e, m, r;

        cin >> s >> e >> m >> r;
        if(s>e) swap(s, e);

        cout << min( max(0, m-s-r)+max(0, e-m-r), e-s) << endl;
    }

    return 0;
}
