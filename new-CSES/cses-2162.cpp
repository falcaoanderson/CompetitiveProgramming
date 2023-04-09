// 09/04/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
 
using namespace std;
 
#define ll long long 
#define endl "\n"
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
inline ll max(ll a, ll b){
    return (a>b? a: b);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    set<int> uset;

    for(int i=1; i<=n; i++) uset.insert(i);

    int crr = 0;

    while(!uset.empty()){
        auto aux = uset.upper_bound(crr);
        if(aux==uset.end()) aux = uset.begin();

        crr = *aux;

        auto rmv = uset.upper_bound(crr);
        if(rmv == uset.end()) rmv = uset.begin();

        cout << (*rmv) << " ";
        crr = *rmv;

        uset.erase(rmv); 
    }
    cout << endl;
 
    return 0;
}
