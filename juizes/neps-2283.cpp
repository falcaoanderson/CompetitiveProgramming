// 10/09/23 //
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
#include <stack>

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

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;

    unordered_map<string, int> vmap;
    vector< pair<int, string> > v(n);

    for(int i=0; i<n; i++){
        cin >> v[i].ss >> v[i].ff;
    }
    sort(v.begin(), v.end());

    ll resp = 0;
    for(int i=n-1; i>=0; i--){
        if(vmap.find(v[i].ss)==vmap.end()){
            vmap[v[i].ss] = 1;
            resp += (ll)v[i].ff;
        }
        else if(vmap[v[i].ss]<k){
            vmap[v[i].ss]++;
            resp += (ll)v[i].ff;
        }
    }

    cout << resp << endl;

    return 0;
}
