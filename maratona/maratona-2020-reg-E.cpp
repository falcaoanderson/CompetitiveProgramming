// 16/10/23 // O(n*logn)
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
#include <functional>
#include <cmath>

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

    int n;
    cin >> n;

    vector<pii> v(n);
    for(int i=0; i<n; i++){
        v[i].ss=i;
        cin >> v[i].ff;
    }

    sort(v.begin(), v.end());
    
    set<int> ind_set;
    vector<int> prefix(n+1);
    
    prefix[0] = 1;
    ind_set.insert(v[n-1].ss);

    for(int i=n-2; i>=0; i--){
        auto it_next = ind_set.upper_bound(v[i].ss);

        if(it_next!=ind_set.end()){
            prefix[(*it_next+v[i].ss+1)/2]--;
        }
        
        if(it_next==ind_set.begin()){
            prefix[0]++;
        }
        else{
            it_next--;
            prefix[(*it_next+v[i].ss)/2 + 1]++;
        }

        ind_set.insert(v[i].ss);
    }

    for(int i=1; i<n; i++){
        prefix[i] += prefix[i-1];
    }
    
    for(int i=0; i<n; i++){
        cout << prefix[i]-1 << " ";
    }
    cout << endl;
    
    
    return 0;
}
