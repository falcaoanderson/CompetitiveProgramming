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

int v[MAXN];

void solve(){
    int n;

    cin >> n;
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v, v+n);

    for(int i=n-1; i>=2; i--){
        int a = v[i], b=v[i-1], c = v[i-2];

        if(a<b+c && b<a+c && c<a+b){
            cout << c << " " << b << " " << a <<endl;
            break;
        }
    }

}

int main(){
    fastio;


    solve();

    return 0;
}
