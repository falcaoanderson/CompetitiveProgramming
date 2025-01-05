/*
04/01/25 
CF 577 Div.2 A
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

int ma[MAXN][10];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;

            ma[j][c-'A']++;
        }
    }

    int resp = 0;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;

        int aux = 0;
        for(int j=0; j<5; j++) aux = max(aux, ma[i][j]);
        resp += aux * a;
    }

    cout << resp << endl;

    return 0;
}
