// 30/06/23 //
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

    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i=0; i<n; i++) cin >> v[i];
    v[n] = v[0];

    int crr=0, resp=0;
    for(int i=1; i<=n; i++){
        if(v[i]+v[i-1]<1000) crr++;
        else{
            resp = max(resp, crr);
            crr = 0;
        }
    }
    resp = max(resp, crr);
    
    cout << resp << endl;

    return 0;
}
