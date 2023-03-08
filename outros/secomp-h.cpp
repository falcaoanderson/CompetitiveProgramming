// 23/10/20 // 12:00 PM //

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

    int n, r;
    cin >> n >> r;
    vector<bool> v(n+1,0);

    for(int i=0; i<r; i++){
        int temp;
        cin >> temp;

        v[temp] = 1;
    }
    bool flag=0;
    for(int i=1; i<=n; i++){
        if(!v[i]){
            cout << i << " ";
            flag = 1;
        }
    }

    if(!flag) cout << "*";
    cout << endl;

    return 0;
}
