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
const int MAXN = (1e2) + 5;
const int MOD  = (1e9) + 7;

int ma[MAXN][MAXN];

int main(){
    fast_io;

    int n, m, h;
    cin >> n >> m >> h;

    vector<int> left(n), front(m);    

    for(int j=0; j<m; j++) cin >> front[j];
    for(int i=0; i<n; i++) cin >> left[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ma[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ma[i][j]){
                ma[i][j] = min(front[j], left[i]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
