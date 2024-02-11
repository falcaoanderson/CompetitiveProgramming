// 02/02/24 //
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
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    while(cin >> n){
        if(n==0) break;

        vector<int> v(n+1);

        for(int i=1; i<=n; i++){
            cin >> v[i];

            v[i] += v[i-1];
        }

        if((v[n]%3)!=0){
            cout << 0 << endl;
            continue;
        }

        int lado = v[n]/3, resp = 0;

        for(int i=2; i<=n; i++){
            int it1 = lower_bound(v.begin(), v.end(), lado+v[i-1])   - v.begin();
            int it2 = lower_bound(v.begin(), v.end(), 2*lado+v[i-1]) - v.begin();

            if(it2<=n && v[it1]-v[i-1]==lado && v[it2]-v[it1]==lado){
                resp++;
            }
        }

        cout << resp << endl;
    }

    return 0;
}
