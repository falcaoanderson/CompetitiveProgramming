// 00/01/20 // 00:00 XM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define int long long

const int INF  = 0x3f3f3f3f;
const int MAXN = (int)(1e3) + 10;
const int MOD  = (int)(1e9) + 7;

int exp(int a, int b){
    if(b==0) return 1;
    if(b==1) return a%MOD;

    a%=MOD;

    if(b&1)
        return (a*exp(a*a, b/2))%MOD;
    else
        return (exp(a*a, b/2))%MOD;
}

bool grid[MAXN][MAXN];
int h, w, r[MAXN], c[MAXN];

void print(){
    cout << endl;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(){
    cin >> h >> w;

    for(int i=1; i<=h; i++) cin >> r[i];
    for(int i=1; i<=w; i++) cin >> c[i];

    bool ok = true;

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(r[i]>=j || c[j]>=i)
                grid[i][j] = 1;
            else
                grid[i][j] = 0;

            if(c[r[i]+1]>=i || r[c[j]+1]>=j) ok = false;
        }
    }

    if(!ok){
        cout << 0 << endl;
        return;
    }

    int cont = 0;
    for(int i=2; i<=h; i++)
        for(int j=2; j<=w; j++)
            if(!grid[i][j] && r[i]<j-1 && c[j]<i-1)
                cont++;

    cout << exp(2, cont) << endl;
}

int32_t main(){
    fastio;

    solve();

    return 0;
}
