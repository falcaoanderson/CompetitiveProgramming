// 03/06/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;
const int MAXLOG = 18;

int boss[MAXN][MAXLOG+5];

int main(){
    fast_io;

    int n, q;

    cin >> n >> q;

    for(int i=2; i<=n; i++){
        cin >> boss[i][0];
    }

    for(int k=1; k<=MAXLOG; k++){
        for(int i=2; i<=n; i++){
            boss[i][k] = boss[boss[i][k-1]][k-1];
        }
    }

    /*
    for(int i=1; i<=n; i++){
        for(int j=0; j<=MAXLOG; j++){
            cout << boss[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl; 
    */
   
    while(q--){
        int a, level;
        cin >> a >> level;

        for(int k=MAXLOG; k>=0; k--){
            if((1<<k)<=level){
                a = boss[a][k];
                level -= (1<<k);
            }
        }   

        cout << (a==0?-1:a) << endl;
    }

    return 0;
}
