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

    int n, d;
    cin >> n >> d;

    int crr=0, best=0, l=1;
    vector<int> v(n+1);

    for(int r=1; r<=n; r++){
        cin >> v[r];

        crr += v[r];
        
        while(l<r && crr>d){
            crr -= v[l];
            l++;
        }

        best = max(best, r-l+1);
    }

    cout << best << endl;

    return 0;
}
