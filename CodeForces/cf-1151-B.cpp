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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector< vector<int> > ma(n, vector<int>(m));
    
    int row=-1, col=-1;
    int aux = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ma[i][j];

            if(row==-1 && ma[i][j]!=ma[i][0]){
                row = i;
                col = j;
            }
        }

        aux ^= ma[i][0];
    }

    if(row==-1 && aux==0){
        cout << "NIE" << endl;
    }
    else{
        vector<int> resp(n);
        aux = 0;

        for(int i=0; i<n; i++){
            if(i==row) continue;

            aux ^= ma[i][0];
            resp[i] = 1;
        }
        
        if(row!=-1){
            if(aux == ma[row][0]){
                resp[row] = col+1;
            }
            else{
                resp[row] = 1;
            }
        }

        cout << "TAK" << endl;
        for(int x: resp) cout << x << " ";
        cout << endl;
    }


    return 0;
}
