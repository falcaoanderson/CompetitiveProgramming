// 07/09/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

char grid[20+5][20+5];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }


    int aux = 0;
    for(int j=0; j<=m; j++){
        for(int i=0; i<n; i++){
            if(aux==0 && grid[i][j]=='v'){
                aux++;
                break;
            }
            if(aux==1 && grid[i][j]=='i'){
                aux++;
                break;
            }
            if(aux==2 && grid[i][j]=='k'){
                aux++;
                break;
            }
            if(aux==3 && grid[i][j]=='a'){
                aux++;
                break;
            }
        }
    }

    if(aux==4){
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
