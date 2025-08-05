/*
01/08/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

    int n, m;
    cin >>n >> m;

    int a=0, b=0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;

        if(x&1){
            a++;
        }
    }

    for(int i=0; i<m; i++){
        int x;
        cin >> x;

        if(x&1){
            b++;
        }
    }

    cout << min(a, m-b) + min(n-a, b) << endl;

    return 0;
}
