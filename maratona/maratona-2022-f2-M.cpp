// 19/09/23 //
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
#include <functional>

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
const int MAXN = (1e3) + 5;
const int MAXM = (1e2) + 5;
const int MOD  = (1e9) + 7;

int n, m;
bool ring[MAXN], grid[MAXN][MAXM], visited[MAXN][MAXM], resp;
bool possible[MAXN][MAXM];

void ini_possible(){
    for(int j=0; j<m; j++) possible[0][j] = 1;

    for(int i=1; i<=n; i++){
        for(int rot=0; rot<m; rot++){
            possible[i][rot] = 1;

            for(int j=0; j<m; j++){
                if(ring[(j+rot)%m] && grid[i][j]){
                    possible[i][rot] = 0;
                    break;
                }
            }
        }
    }
}

void dfs(int i, int rot){
    if(resp) return;
    if(i==n){
        resp = 1;
        return;
    }

    visited[i][rot] = 1;

    if(!visited[i+1][rot] && possible[i+1][rot]) dfs(i+1, rot);
    if(i>1 && !visited[i-1][rot] && possible[i-1][rot]) dfs(i-1, rot);

    for(int k=rot+1; k<rot+m; k++){
        int nrot = k%m;

        if(possible[i][nrot]){
            if(!visited[i][nrot]) dfs(i, nrot);
        }
        else{
            break;
        }
    }
    for(int k=rot-1; k>rot-m; k--){
        int nrot = (k+m)%m;

        if(possible[i][nrot]){
            if(!visited[i][nrot]) dfs(i, nrot);
        }
        else{
            break;
        }
    }
}

int main(){
    fast_io;

    cin >> n >> m;
    
    for(int j=0; j<m; j++){
        char c;
        cin >> c;

        ring[j] = (c=='1');
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            
            grid[i][j] = (c=='1');
        }
    }
    
    resp = 0;
    ini_possible();
    dfs(0, 0);

    if(resp){
        cout << "Y" << endl;
        return 0;
    }

    for(int j=0; j<m/2; j++) swap(ring[j], ring[m-j-1]); 
    memset(visited, 0, sizeof(visited));

    resp = 0;
    ini_possible();
    dfs(0, 0);

    if(resp){
        cout << "Y" << endl;
        return 0;
    }

    cout << "N" << endl;

    return 0;
}
