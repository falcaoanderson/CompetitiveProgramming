// 18/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e3) + 10;
const int MOD  = (1e9) + 7;

int n, q;
int prefix[MAXN][MAXN];

int main(){
    fast_io;
    
    cin >> n >> q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c;
            cin >> c;

            if(c=='*') prefix[i][j] = 1;

            prefix[i][j] += prefix[i][j-1];
        }
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            prefix[i][j] += prefix[i-1][j];
      
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1] << endl;
    }

    return 0;
}