// 29/01/23 //
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
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    cin >> n;

    set<int> segment;
    int l=0;

    vector<pii> resp;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        if(segment.find(val)!=segment.end()){
            resp.EB(l+1, i+1);

            segment.clear();
            l = i+1;
        }
        else{
            segment.insert(val);
        }
    }

    if(resp.empty()){
        cout << -1 << endl;
    }
    else{
        resp[resp.size()-1].SS = n;
        
        cout << resp.size() << endl;
        for(pii x: resp){
            cout << x.FF << " " << x.SS << endl;
        }
    }

    return 0;
}
