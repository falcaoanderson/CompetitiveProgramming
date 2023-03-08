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
    int n, b, g;

    cin >> b >> g >> n;

    int maxb = min(n, b);
    int maxg = min(n, g);
    int minb = n-maxg;
    int ming = n-maxb;

    int cont=0;
    for(int i=0; i<=n; i++){
        if((minb <= i && i<=maxb)&&(ming <= (n-i) && (n-i)<=maxg)){
            cont ++;
        }
    }

    cout << cont << endl;
}

int main(){
    fastio;


    solve();

    return 0;
}
