// 13/04/23 // solucao iterativa
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
    
    int n;
    cin >> n;

    vector<int> solve(n+1);
    
    for(int val=1; val<=n; val++){
        int aux = val;
        
        solve[val] = INF;

        while(aux){
            solve[val] = min(solve[val], 1 + solve[val-aux%10]);

            aux /= 10;
        }
    }
    
    cout << solve[n] << endl;

    return 0;
}