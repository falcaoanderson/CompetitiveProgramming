/*
26/08/25 

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
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    vector<vector<int>> memo(n, vector<int>(m));

    memo[0][0] = (a[0]==b[0]);
    for(int i=1; i<n; i++)
        memo[i][0] = max(memo[i-1][0], (int)(a[i]==b[0]));
    for(int i=1; i<m; i++)
        memo[0][i] = max(memo[0][i-1], (int)(a[0]==b[i]));

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(a[i]==b[j]){
                memo[i][j] = memo[i-1][j-1] + 1;
            }
            else{
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    vector<int> resp;
    int x = n-1, y = m-1;
    while(x>=0 && y>=0){
        if(a[x]==b[y]){
            resp.PB(a[x]);
            x--;
            y--;
        }
        else if(x==0){
            y--;
        }
        else if(y==0){
            x--;
        }
        else if(memo[x-1][y]>memo[x][y-1]){
            x--;
        }
        else{
            y--;
        }
    }

    cout << resp.size() << endl;
    for(int i=SZ(resp)-1; i>=0; i--) cout << resp[i] << " ";
    cout << endl;

    return 0;
}
