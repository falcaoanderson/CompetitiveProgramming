// 02/05/23 // prefix sum
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
 
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int INF  = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
 
int main(){
    fast_io;
    
    int n, q;
 
    cin >> n >> q;
    
    vector<int> v(n+1);

    for(int i=1; i<=n; i++){
        cin >> v[i];

        v[i] ^= v[i-1];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        
        cout << (v[b] ^ v[a-1]) << endl;    
    }
 
    return 0;
}