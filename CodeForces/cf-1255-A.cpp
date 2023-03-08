// 00/00/20 // 00:00 XX //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

void solve(){
    int a, b , dif;
    cin >> a >> b;
    dif = abs(b-a);

    int resp = dif/5;

    if(dif%5 == 1 || dif%5 == 2)
        resp+=1;
    if(dif%5 == 3 || dif%5 == 4)
        resp+=2;

    cout << resp << endl;
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
