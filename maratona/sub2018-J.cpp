/*
21/08/25 

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
const double DINF = 1e9;
const int MAXN = (1e2) + 5;
const int MAXK = 10;

int n, k;
int cx[MAXN], cy[MAXN];
double dist[MAXN][MAXN];
double memo[MAXN][(1<<MAXK) + 5];

double euc_dist(int u, int v){
    return sqrt( (double)((cx[u]-cx[v])*(cx[u]-cx[v]) + (cy[u]-cy[v])*(cy[u]-cy[v])) );
}

void steiner_tree(){
    // Floyd-Warshall
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    // Steiner Tree
    for(int i=0; i<n; i++){
        for(int mask=0; mask<(1<<k); mask++){
            memo[i][mask] = DINF;
        }
    }
    for(int i=0; i<k; i++){
        memo[i][(1<<i)] = 0;
    }

    for(int mask=0; mask<(1<<k); mask++){
        for(int i=0; i<n; i++){
            for(int submask=mask; submask>0 && i>=k; submask=(submask-1)&mask){
                memo[i][mask] = min(memo[i][mask], memo[i][submask] + memo[i][mask-submask]);
            }

            if(memo[i][mask]>=DINF) continue;

            for(int j=(i<k? k: 0); j<n; j++){
                memo[j][mask] = min(memo[j][mask], memo[i][mask] + dist[i][j]);
            }
        }
    }
}

int main(){
    fast_io;

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> cx[i] >> cy[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            dist[i][j] = dist[j][i] = euc_dist(i, j);
        }
    }

    steiner_tree();

    double resp = DINF;
    for(int i=0; i<n; i++){
        resp = min(resp, memo[i][(1<<k)-1]);
    }

    cout.precision(5);
    cout.setf(ios_base::fixed);
    cout << resp << endl;

    return 0;
}
