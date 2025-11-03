/*
30/10/25 

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
const int MAXN = (1e2) + 5;
const int MOD  = (1e9) + 7;

bool grid[MAXN][MAXN];

bool bad(int i, int j){
    return (grid[i][j] && grid[i-1][j] && grid[i+1][j]) || (grid[i][j] && grid[i][j-1] && grid[i][j+1]); 
}

void solve(){
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        string s;
        cin >> s;

        for(int j=1; j<=n; j++){
            grid[i][j] = (s[j-1]=='#');
        }

        grid[n+1][i] = grid[i][n+1] = 0; 
    }
    
    bool resp = 1;
    int qnt = 0, quadra=0;
    set<int> pdiag, sdiag;

    for(int i=1; i<=n && resp; i++){
        for(int j=1; j<=n && resp; j++){
            if(grid[i][j]){
                resp = !bad(i, j);

                pdiag.insert(i-j);
                sdiag.insert(i+j);
                
                qnt++;
                if(quadra==0){
                    quadra = 1 + (int)grid[i][j+1] + (int)grid[i+1][j] + (int)grid[i+1][j+1];
                }
            }
        }
    }

    if(!resp){
        cout << "NO" << endl;
        return;
    }
    
    if(qnt==0){
        cout << "YES" << endl;
    }
    else if(qnt==4 && qnt==quadra){
        cout << "YES" << endl;
    }
    else if(pdiag.size()==1 || sdiag.size()==1){
        cout << "YES" << endl;
    }
    else if(pdiag.size()==2 && (*pdiag.rbegin() - *pdiag.begin())==1){
        cout << "YES" << endl;
    }
    else if(sdiag.size()==2 && (*sdiag.rbegin() - *sdiag.begin())==1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    fast_io;
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
