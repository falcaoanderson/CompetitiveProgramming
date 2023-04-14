// 14/04/23 // iterativo com otimizacao de memoria
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
  
const int MAXX = 1e5+5;

int memo[5][MAXX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;

    vector<int> price(n+1), pages(n+1);

    for(int i=1; i<=n; i++){
        cin >> price[i];
    }
    for(int i=1; i<=n; i++){
        cin >> pages[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            if(price[i]<=j) memo[i&1][j] = max(memo[(i-1)&1][j], memo[(i-1)&1][j-price[i]]+pages[i]);
            else            memo[i&1][j] = memo[(i-1)&1][j];
        }
    }

    cout << memo[n&1][x] << endl;

    return 0;
}
