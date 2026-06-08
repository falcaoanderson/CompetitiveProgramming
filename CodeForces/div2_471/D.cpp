/*
28/01/26

*/
#include <bits/stdc++.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl "\n"
#define FF first
#define SS second
#define PB push_back
#define EB emplace_back

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

// const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

vector<int> z_function(vector<int> &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main(){
    fast_io;

    int n, w;
    cin >> n >> w;

    vector<int> va(n-1), vb(w-1);
    int last;

    cin >> last;
    for(int i=0; i<n-1; i++){
        cin >> va[i];
        va[i] -= last;
        last = va[i] + last;
    }

    cin >> last;
    for(int i=0; i<w-1; i++){
        cin >> vb[i];
        vb[i] -= last;
        last = vb[i] + last;
    }

    if(w==1){
        cout << n << endl;
        return 0;
    }
    if(n<w){
        cout << 0 << endl;
        return 0;
    }

    vb.push_back(INF);
    for(int x: va) vb.push_back(x);
    // for(int x: vb) cout << x << " ";
    // cout << endl;
    vector<int> z = z_function(vb);

    int ans = 0;
    for(int i=w; i<n+w-1; i++){
        ans += (z[i]==w-1);
    }
    cout << ans << endl;

    return 0;
}