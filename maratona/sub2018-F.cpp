/*
16/08/25 

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
const int MAXN = 1050;
const int MOD  = (1e9) + 7;

int n, total=0;
int ordem[MAXN];
int ini[MAXN], fim[MAXN], val[MAXN], palco[MAXN];
int memo[MAXN][MAXN];

int find_next(int i){
    int l = i+1, r = total-1, mid, resp=total;

    while(l<=r){
        mid = (l+r)/2;

        if(ini[ordem[mid]]>=fim[ordem[i]]){
            resp = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    return resp;
}

int solve(int i, int mask){
    if(memo[i][mask]!=-1) return memo[i][mask];
    
    int idx = ordem[i];

    if(i>=total){
        if(mask == ((1<<n)-1)){
            return 0;
        }
        else{
            return -INF;
        }
        cout << endl;
    }

    int prox_i = find_next(i);

    // nao assiste
    memo[i][mask] = solve(i+1, mask);
    // assiste
    memo[i][mask] = max(memo[i][mask], 
                        solve(prox_i, mask|(1<<palco[idx])) + val[idx]);

    return memo[i][mask];
}

bool comp(int a, int b){
    return ini[a]<ini[b];
}

int main(){
    fast_io;

    cin >> n;
    for(int i=0; i<n; i++){
        int tam;
        cin >> tam;

        for(int j=0; j<tam; j++){
            cin >> ini[total] >> fim[total] >> val[total];
            palco[total] = i;
            total++;
        }
    }

    for(int i=0; i<total; i++) ordem[i]=i;
    sort(ordem, ordem+total, comp);

    memset(memo, -1, sizeof(memo));
    
    int r = solve(0, 0); 
    cout << (r<=(int)(1e6)-INF?-1:r) << endl;

    return 0;
}
