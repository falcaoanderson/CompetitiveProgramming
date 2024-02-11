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
const int MAXN = 20;
const int MOD  = (1e9) + 7;

int n, m;
vector<int> v, vf;

bool solve(int l){
    if(l<m) return 0;

    if(l==m){
        if(v==vf) return 1;

        reverse(v.begin(), v.end());
        if(v==vf) return 1;
        reverse(v.begin(), v.end());

        return 0;
    }

    for(int c=0; c<l-1; c++){
        int new_l = max(c+1, l-c-1);

        vector<int> new_v(new_l);

        int ind = new_l;
        for(int i=c; i>=0; i--){
            new_v[--ind] += v[i];
        }

        ind = new_l;
        for(int i=c+1; i<l; i++){
            new_v[--ind] += v[i];
        }

        swap(v, new_v);
        if(solve(new_l)) return 1;
        swap(v, new_v);
    }

    return 0;
}

int main(){
    fast_io;

    while(cin >> n){
        if(n==0) break;

        v.resize(n);
        for(int i=0; i<n; i++) cin >> v[i];

        cin >> m;
        vf.resize(m);
        for(int i=0; i<m; i++) cin >> vf[i];

        cout << (solve(n)?"S":"N") << endl;
    }

    return 0;
}
