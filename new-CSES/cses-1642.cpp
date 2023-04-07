// 07/04/23 //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
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
    
    int n, x;
    cin >> n >> x;
    
    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    vector<tiii>  sum_val;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int crr_sum = v[i]+v[j]; 

            sum_val.EB(crr_sum, i, j);
        }
    }

    sort(sum_val.begin(), sum_val.end());

    for(auto curr: sum_val){
        int sum, i, j;
        tie(sum, i, j) = curr;
        
        int need_sum = x-sum;

        auto it = upper_bound(sum_val.begin(), sum_val.end(), tiii(need_sum, j, n));

        if(it!=sum_val.end() && get<0>(*it) == need_sum){
            cout << i+1 << " " << j+1 << " " << get<1>(*it)+1 << " " << get<2>(*it)+1 << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}