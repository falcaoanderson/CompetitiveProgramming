/*
20/01/26
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

const int MAXVAL = 1e6 + 5;
const int MAXN = 1e5 + 5;

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        if(k>=n-1){
            cout << 1 << endl;
        }
        else{
            cout << n << endl;
        }
    }


    return 0;
}