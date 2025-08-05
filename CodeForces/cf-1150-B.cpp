/*
05/08/25 

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

bool grid[MAXN][MAXN];

int aux_x[] = {1, 1, 1, 2, 0, 0};
int aux_y[] = {-1, 0, 1, 0, 0, 0};

int main(){
    fast_io;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c;

            grid[i][j] = (c=='#');
        }
    }

    bool resp = 1;

    for(int i=0; i<n && resp; i++){
        for(int j=0; j<n && resp; j++){
            if(!grid[i][j]){
                grid[i][j] = 1;

                for(int k=0; k<4; k++){
                    int ni = i + aux_x[k];
                    int nj = j + aux_y[k];

                    if(0<=ni && ni<n && 0<=nj && nj<n && !grid[ni][nj]){
                        grid[ni][nj] = 1;
                    }
                    else{
                        resp = 0;
                        break;
                    }
                }
            }
        }
    }

    cout << (resp?"YES":"NO") << endl;

    return 0;
}
