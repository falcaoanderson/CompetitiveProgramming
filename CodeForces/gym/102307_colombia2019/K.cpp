/*
26/01/26

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

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << (n/3) * 2 + (int)(n > 2) - (int)((n%3) == 0) << endl;  
    }

    return 0;
}