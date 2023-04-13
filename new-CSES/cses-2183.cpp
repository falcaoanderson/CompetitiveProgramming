// 13/04/23 //
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
  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    ll prefix = 0LL;
    
    for(int i=0; i<=n; i++){
        prefix += (ll)v[i];

        if(i==n || (ll)v[i+1]>prefix+1LL){    
            break;
        }
    }

    cout << prefix+1LL << endl;

    return 0;
}