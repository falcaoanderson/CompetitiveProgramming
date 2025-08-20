/*
20/08/25 

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
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e2) + 5;
const int MAXVAL = (2e2) + 5;
const int MOD  = (1e9) + 7;

bool vaux[MAXVAL];
int grid[MAXN][MAXN];

int main(){
    fast_io;

    int n;
    cin >> n;
    
    for(int k=2; k<=100; k++){
        grid[1][k] = grid[k][1] = k-2;
    }
    for(int i=2; i<=100; i++){
        for(int j=2; j<=100; j++){
            if(i==j) continue;

            memset(vaux, 0, sizeof(vaux));

            for(int k=i-1; k>=1; k--){
                if(k==j) continue;
                vaux[grid[k][j]] = 1;
            }
            for(int k=j-1; k>=1; k--){
                if(k==i) continue;
                vaux[grid[i][k]] = 1;
            }
            for(int k=1; min(i, j)-k>=1; k++){
                vaux[grid[i-k][j-k]] = 1;
            }

            int val = -1;
            for(int k=0; k<=(int)2e2; k++){
                if(vaux[k]==0){
                    val = k;
                    break;
                }
            }

            grid[i][j] = val;
        }
    }

    int nimsum = 0;
    bool insta_win = 0;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        if(x==y) insta_win = 1;

        nimsum ^= grid[x][y];
    }

    cout << (insta_win || nimsum!=0? "Y": "N") << endl;

    return 0;
}
