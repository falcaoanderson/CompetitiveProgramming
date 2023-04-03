// 03/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
 
#define endl "\n"
#define PB push_back

typedef pair<int, int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, n;
    cin >> x >> n;

    set<pii> intervals;
    multiset<int> lenghts;

    intervals.insert({0, x});
    lenghts.insert(x);

    while(n--){
        int t;
        cin >> t;

        auto it = intervals.upper_bound({t, 0});
        it--;

        int a = (it->first), b = (it->second);

        intervals.erase(it);
        lenghts.erase(lenghts.find(b-a));
        
        intervals.emplace(a, t);
        intervals.emplace(t, b);
        lenghts.insert(t-a);
        lenghts.insert(b-t);

        cout << (*lenghts.rbegin()) << " ";
    }
    cout << endl;
     
    return 0;
}