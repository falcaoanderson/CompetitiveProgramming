/*
03/03/26 

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

const int n = 8, dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};
double P[15][15][5];

double moves(int i, int j){
    if((i == 1 || i == n) && (j==1 || j==n)) return 2.0;
    else if(i == 1 || i == n || j==1 || j==n) return 3.0;
    return 4.0;
}
bool in_grid(int ni, int nj){
    return 1<=ni && ni<=n && 1<=nj && nj<=n;
}

int main(){
    fast_io;
    
    int k;
    cin >> k;

    for(int t=1; t<=k; t++){
        for(int i=1; i<=8; i++){
            for(int j=1; j<=8; j++){

                P[i][j][t % 2] = 1.0;
                for(int z=0; z<4; z++){
                    int ni = i + dx[z], nj = j + dy[z];
                    double q = moves(ni, nj);
                    if(in_grid(ni, nj)){
                        P[i][j][t % 2] *= (P[ni][nj][(t+1) % 2] + (1.0 - P[ni][nj][(t+1) % 2]) * ((q - 1.0) / q));   
                    }
                }
            }
        }
    }

    double ans = 0;
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            ans += P[i][j][k % 2];
        }
    }

    cout.precision(12);
    cout.setf(ios::fixed);
    cout << ans << endl;

    return 0;
}
