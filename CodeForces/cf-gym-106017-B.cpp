/*
08/09/25 

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
const int MAXN = 60 + 5;
const int MOD  = (1e9) + 7;

int n, m, t;
char grid[MAXN][MAXN];
set<ll> visited;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool in_grid(int x, int y){
    return 0<=x && x<n && 0<=y && y<m;
}

ll move(vector<int> balls, int k){
    for(int i=0; i<t; i++){
        int x=balls[i]/m, y=balls[i]%m;
        grid[x][y] = 'X';
    }

    ll state=0;
    for(int i=0; i<t; i++){
        int x=balls[i]/m, y=balls[i]%m;
        int nx=x, ny=y;

        while(in_grid(nx, ny) && grid[nx][ny]!='#'){
            if(grid[nx][ny]=='.'){
                swap(grid[x][y], grid[nx][ny]);
                x = nx;
                y = ny;
            }
            nx = nx + dx[k];
            ny = ny + dy[k];
        }

        balls[i] = x*m+y;

        state ^= (1LL<<(ll)balls[i]);
    }

    for(int i=0; i<t; i++){
        int x=balls[i]/m, y=balls[i]%m;
        grid[x][y] = '.';
    }

    return state;
}

bool solve(ll start, ll dest){
    vector<int> balls(t);
    queue<ll> fila;
    fila.push(start);
    visited.insert(start);

    while(!fila.empty()){
        ll crr = fila.front();
        fila.pop();

        if(crr==dest) return 1;

        int aux = 0;
        for(ll i=0; i<n*m; i++){
            if((crr&(1LL<<i))!=0){
                balls[aux++] = i;
            }
        }
        
        for(int k=0; k<4; k++){
            ll nxt = move(balls, k);

            if(visited.find(nxt)==visited.end()){
                fila.push(nxt);
                visited.insert(nxt);
            }
        }

    }

    return 0;
}

int main(){
    fast_io;

    cin >> n >> m;
    
    ll start=0, dest=0;
    int cnt = 0;
    bool flag=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            
            if(grid[i][j]=='X'){
                ll idx = i*m+j;
                start ^= (1LL<<idx);
                grid[i][j] = '.';
                cnt++;
                t++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            
            if(c=='X'){
                ll idx = i*m+j;
                dest ^= (1LL<<idx);
                c = '.';
                cnt--;
            }

            if((c=='#' && grid[i][j]=='.') || (grid[i][j]=='#' && c=='.')) flag = 0;
        }
    }

    if(!flag || cnt!=0){
        cout << "NO" << endl;
        return 0;
    }   

    cout << (solve(start, dest)?"YES":"NO") << endl;

    return 0;
}
