// 04/07/23 //
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

    int n, m;
    cin >> n >> m;

    set<int> v;
    vector<int> defeat(n+1);

    for(int i=1; i<=n; i++) v.insert(i);

    while(m--){
        int l, r, x;
        cin >> l >> r >> x;

        auto it = v.lower_bound(l);
        vector<int> remove;
        
        while(it!=v.end() && (*it) <= r){
            if((*it)!=x){
                remove.PB(*it);
            }

            it++;
        }

        for(int i: remove){
            defeat[i] = x;
            v.erase(i);
        }
    }

    for(int i=1; i<=n; i++) cout << defeat[i] << " ";
    cout << endl;

    return 0;
}
