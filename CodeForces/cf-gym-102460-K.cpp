// 27/01/24 //
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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        priority_queue<int> v;

        for(int i=1; i<=n; i++){
            int val;
            cin >> val;

            v.push(-val);
        }
        
        ll resp = 0;

        while(v.size()>1){
            int a, b;
            a = v.top();v.pop();
            b = v.top();v.pop();

            resp -= (ll)(a+b);

            v.push(a+b);
        }

        cout << resp << endl;
    }

    return 0;
}
