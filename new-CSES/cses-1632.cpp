// 08/04/23 //
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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<pii> v(n, pii(0,0));

    for(int i=0; i<n; i++){
        cin >> v[i].ss >> v[i].ff;
    }

    sort(v.begin(), v.end());

    multiset<int> mset;   

    for(int i=0; i<k; i++){
        mset.insert(0);
    }

    int resp = 0;
    for(pii movie: v){
        auto crr = mset.upper_bound(movie.ss);

        if(crr != mset.begin()){
            crr--;
            
            mset.erase(crr);
            mset.insert(movie.ff);

            resp++;
        }
    }

    cout << resp << endl;

    return 0;
}