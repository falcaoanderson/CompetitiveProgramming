// 19/04/23 // dp iterativa
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
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int MAXN = 1e2+5;
const int MAXVAL = 1e5+5;

bool solve[MAXN][MAXVAL]; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> coins(n+1);
    int max_sum=0;

    for(int i=1; i<=n; i++){
        cin >> coins[i];
        max_sum += coins[i];
    }

    //solve[i][j] = se eu consigo ou nao formar j com as i primeiras moedas.
    solve[0][0] = 1;

    for(int i=1; i<=n; i++){
        solve[i][0] = 1;

        for(int j=1; j<=max_sum; j++){
            solve[i][j] = solve[i-1][j];

            if(j>=coins[i]){
                solve[i][j] = solve[i][j] || solve[i-1][j-coins[i]]; 
            }
        }
    }

    int count=0;
    for(int j=1; j<=max_sum; j++){
        count += (int)solve[n][j];
    }
    
    cout << count << endl;

    for(int j=1; j<=max_sum; j++){
        if(solve[n][j]) cout << j << " ";
    }
    cout << endl;
    
    return 0;
}