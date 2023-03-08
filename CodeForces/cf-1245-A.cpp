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

const int INF = 0x3f3f3f3f;
const int MAXN = (int)(1e5) + 10;


int mdc(int a, int b){
    return b==0? a: mdc(b, a%b);
}

void solve(){
    int a, b;
    cin >> a >> b;

    if(mdc(a, b)==1){
        cout << "Finite\n";
    }
    else{
        cout << "Infinite\n";
    }
}

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
