/*
30/07/25 

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
const int MAXN = 55;
const int MOD  = (1e9) + 7;

int ma[MAXN][MAXN], mb[MAXN][MAXN];

int main(){
    fast_io;
    
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> ma[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mb[i][j];
        }
    }

    bool resp = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(ma[i][j]>mb[i][j])
                swap(ma[i][j], mb[i][j]);

            if(ma[i][j]<=ma[i][j-1] || ma[i][j]<=ma[i-1][j])
                resp = 0;
            if(mb[i][j]<=mb[i][j-1] || mb[i][j]<=mb[i-1][j])
                resp = 0;
        }
    }

    cout << (resp?"Possible":"Impossible") << endl;

    return 0;
}
