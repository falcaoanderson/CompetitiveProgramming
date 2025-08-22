/*
21/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n, a, b, c;
        cin >> n >> a >> b;

        if(a+b>n || (a*b==0 && a+b>0)){
            cout << "NO" << endl;
            continue;
        }

        c = n - a - b;

        cout << "YES" << endl;

        for(int i=1; i<=a; i++)     cout << n-c-a+i << " ";
        for(int i=1; i<=b; i++)     cout << i << " ";
        for(int i=n-c+1; i<=n; i++) cout << i << " ";
        cout << endl;

        for(int i=1; i<=n; i++) cout << i << " ";
        cout << endl;
    }

    return 0;
}
