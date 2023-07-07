// 07/07/23 //
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

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n, s;
    cin >> n >> s;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll resp = 0LL;

    if(v[n/2]<=s){
        for(int i=n/2; i<n; i++){
            if(v[i]<s){
                resp += (ll)(s-v[i]);
            }
        }
    }
    else{
        for(int i=n/2; i>=0; i--){
            if(v[i]>s){
                resp += (ll)(v[i]-s);
            }
        }
    }

    cout << resp << endl;

    return 0;
}
