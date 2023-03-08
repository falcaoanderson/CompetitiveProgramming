// 21/10/20 // 6:43 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
//#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n+1);

    for(int i=0; i<n; i++) cin >> v[i];
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    int qnt = 1, r=v[1]-v[0];

    for(int i=1; i<n; i++){
        int tr = v[i]-v[i-1];

        if(r!=tr){
            qnt++;
            r = v[i+1]-v[i];
        }
    }

    cout << qnt << endl;

    return 0;
}
