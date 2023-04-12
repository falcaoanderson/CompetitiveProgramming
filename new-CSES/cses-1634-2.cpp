// 12/04/23 // solucao iterativa
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

const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    } 

    vector<int> solve(x+1);

    for(int val=1; val<=x; val++){
        solve[val] = INF;

        for(int i=0; i<n; i++){
            if(val>=coins[i]) solve[val] = min(solve[val], solve[val-coins[i]]+1);
        }
    }

    cout << (solve[x]<INF? solve[x]: -1) << endl;

    
    return 0;
}