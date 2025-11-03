/*
25/10/25 

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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n), copy_grid(n);
    vector<pii> fst(26, {-1, -1}), lst(26, {-1, -1});
    int maxid=-1;

    for(int i=0; i<n; i++){
        cin >> grid[i];
        copy_grid[i] = grid[i];

        for(int j=0; j<m; j++){
            copy_grid[i][j] = '.';

            if(grid[i][j]!='.'){
                int id = grid[i][j] - 'a';
                maxid = max(maxid, id);

                if(fst[id].FF==-1){
                    fst[id] = {i, j};
                }
                lst[id] = {i, j};
            }
        }
    }

    for(int i=maxid-1; i>=0; i--){
        if(fst[i].FF==-1){
            fst[i] = fst[i+1];
            lst[i] = lst[i+1];
        }
    }

    bool flag = 1;

    for(int id=0; id<=maxid; id++){
        if(id<25 && fst[id]==fst[id+1] && lst[id]==lst[id+1]) continue;

        if(fst[id].FF == lst[id].FF){
            int i = fst[id].FF;
            for(int j=fst[id].SS; j<=lst[id].SS; j++){
                copy_grid[i][j] = (char)('a' + id);
            }
        }
        else if(fst[id].SS == lst[id].SS){
            int j = fst[id].SS;
            for(int i=fst[id].FF; i<=lst[id].FF; i++){
                copy_grid[i][j] = (char)('a' + id);
            }
        }
        else{
            flag = 0;
            break;
        }
    }

    if(flag && grid==copy_grid){
        cout << "YES" << endl;
        cout << maxid+1 << endl;
        for(int id=0; id<=maxid; id++){
            cout << fst[id].FF+1 << " " << fst[id].SS+1 << " " << lst[id].FF+1 << " " << lst[id].SS+1 << endl;
        }
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
