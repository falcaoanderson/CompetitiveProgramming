// 09/10/20 // 13:55 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int v, t;
    cin >> v >> t;

    while(t--){
        int temp;
        cin >> temp;

        v += temp;
        v = max(0, v);
        v = min(100, v);
    }

    cout << v << endl;

    return 0;
}

