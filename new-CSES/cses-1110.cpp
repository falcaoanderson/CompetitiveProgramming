/*
07/03/26 

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

int main(){
    fast_io;

    string s;
    cin >> s;

    int n = SZ(s);
    s += s + "#";

    int st = 0, l = 0, r = 0;
    vector<int> z(n);

    for(int i = 1; i < n; i++){
        z[i] = max(0, min(r - i, z[i - l]));
        while(i + z[i] < 2*n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }

        if(s[st + z[i]] > s[i + z[i]]){
            st = i;
            l = i;
            r = i;
            z[i] = 0;
        }
    }

    for(int i = st; i < st + n; i++) cout << s[i];
    cout << endl;

    return 0;
}
