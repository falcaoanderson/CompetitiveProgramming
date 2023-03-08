// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
//#define int long long

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;


void solve(){

    int x;
    cin >> x;

    cout << ((x - 9)>=0 ? (x-9)%24: 24 + (x-9)%24) << endl;

}

int main(){
    fastio;

    solve();

    return 0;
}

