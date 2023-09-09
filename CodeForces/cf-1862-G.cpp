// 09/09/23 //
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

void solve(){
    int n;
    cin >> n;

    vector<int> v(n), vsorted(n);
    multiset<int> vset, diff;

    for(int i=0; i<n; i++){
        cin >> v[i];
        
        vsorted[i] = v[i];
        vset.insert(v[i]);
    }

    sort(vsorted.begin(), vsorted.end());
    for(int i=1; i<n; i++) diff.insert(vsorted[i]-vsorted[i-1]);

    int q;
    cin >> q;

    while(q--){
        int i, val;
        cin >> i >> val; i--;

        if(n==1){
            cout << val << " ";
            continue;
        }

        // ------- removendo ------
        int val_prev=-1, val_next=-1;
        auto it_fixed = vset.find(v[i]);
        
        auto it = it_fixed;
        if(it!=vset.begin()){
            it--;
            val_prev = *it;

            diff.erase( diff.find(v[i] - val_prev) );
        }

        it = it_fixed; it++;
        if(it!=vset.end()){
            val_next = *it;

            diff.erase( diff.find(val_next - v[i]) );
        }
        vset.erase(it_fixed);

        if(val_next!=-1 && val_prev!=-1){
            diff.insert(val_next-val_prev);
        }

        // ------- adicionando ------
        v[i] = val;
        val_prev=-1, val_next=-1; 
        it_fixed = vset.insert(val);
        
        it = it_fixed;
        if(it!=vset.begin()){
            it--;
            val_prev = *it;

            diff.insert(val - val_prev);
        }

        it = it_fixed; it++;
        if(it!=vset.end()){
            val_next = *it;
            diff.insert(val_next - val);
        }

        if(val_prev!=-1 && val_next!=-1){
            diff.erase(diff.find(val_next-val_prev));
        }
        // -------------------

        cout << (*vset.rbegin()) + (*diff.rbegin()) << " ";
    }
    cout << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
