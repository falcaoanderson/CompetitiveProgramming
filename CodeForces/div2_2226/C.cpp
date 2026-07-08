/*
28/04/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

bool check(vector<int>& v, int value){
    int n = SZ(v);
    set<int> numbers;
    for(int i=0; i<value; i++) numbers.insert(i);

    for(int i=0; i<n && !numbers.empty(); i++){
        if(numbers.find(v[i]) != numbers.end()){
            numbers.erase(v[i]);
        }
        else{
            int up_val = (v[i] - 1) / 2;

            auto it = numbers.upper_bound(up_val);

            if(it != numbers.begin()){
                it--;
                numbers.erase(it);
            }
        }
    }

    return numbers.empty();
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int l = 1, r = n, ans = 0;

    while(l <= r){
        int mid = (l + r) / 2;

        if(check(v, mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }


    cout << ans << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
