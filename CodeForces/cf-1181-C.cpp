/*
20/07/25 

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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int n, m;
char grid[MAXN][MAXN];
int col_cnt[MAXN][MAXN], gflag[MAXN][MAXN], flag_cnt[MAXN][MAXN];

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    ll resp = 0;

    for(int j=0; j<m; j++){
        for(int i=n-1; i>=0; i--){
            if(i==n-1 || grid[i][j]!=grid[i+1][j]){
                col_cnt[i][j]=0;
            }
            else{
                col_cnt[i][j]=col_cnt[i+1][j]+1;
            }
            

            bool flag=1;
            int num=0, aux=1, crr_i=i;
            for(int k=0; k<3; k++){
                num += (grid[crr_i][j]-'a') * aux;
                aux *= 26;
                
                if(k==2) break;
                
                int nxt_i = crr_i+col_cnt[crr_i][j]+1;

                if(nxt_i>=n || grid[crr_i][j]==grid[nxt_i][j] || 
                  (k==0 && col_cnt[crr_i][j]!=col_cnt[nxt_i][j]) ||
                  (k==1 && col_cnt[crr_i][j]>col_cnt[nxt_i][j])){
                    flag=0;
                    break;
                }
                crr_i=nxt_i;
            }

            if(flag){
                gflag[i][j] = num;
                resp++;
            }
            else{
                gflag[i][j] = -1;
            }

            if(flag && j>0 && gflag[i][j]==gflag[i][j-1] &&
               col_cnt[i][j]==col_cnt[i][j-1]){ 

                flag_cnt[i][j] = flag_cnt[i][j-1]+1;
                resp += (ll)flag_cnt[i][j];
            }
        }
    }

    cout << resp << endl;

    return 0;
}
