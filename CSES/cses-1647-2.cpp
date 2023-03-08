// 21/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;
const int MOD  = (1e9) + 7;

int n, q;
int table[MAXN][20];

int main(){
    fast_io;

    cin >> n >> q;
    for(int i=1; i<=n; i++)
        cin >> table[i][0];

    /*
    table[i][j] = min(table[i][j-1], table[i+1<<(j-1)][j-1])

    table[i][j] == min [i, i + 1<<j -1]
    */

    for(int j=1; j<19; j++){
        for(int i=1; i<=n; i++){
            if( (i-1+(1<<j)) > n) break;

            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }

    /*                  
    min [i, j] = min(table[i][mp], table[j - 1<<mp +1][mp])
    mp = log(j-i+1) // maior potencia de 2

    table[i][mp] == min [i, i + 1<<mp - 1]
    table[j - 1<<mp +1][mp] == min [j - 1<<mp +1][j - 1<<mp +1 +1<<mp -1] == min [j - 1<<mp +1][j]
    
    ex:
                      min[2,3]     min[4, 5]
    min [2, 5] = min(table[2][1], table[4][1])
    */

    vector<int> log(n+1);
    for(int i=2; i<=n; i++) log[i] = log[i/2] + 1;  
    
    while(q--){
        int a, b;
        cin >> a >> b;
        
        int mp = log[b-a+1];

        cout << min(table[a][mp], table[b-(1<<mp)+1][mp]) << endl;
    }

    return 0;
}
