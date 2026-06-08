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

    int n, m, k;
    cin >> n >> m >> k;

    cout.precision(9);
    cout.setf(ios::fixed);

    if(m>=k){
        cout << (double)(k-1) / (double)(k) + (double)(m-(k-1)) / (double)(m-(k-1) + n) / (double)(k)<< endl;   
    }
    else{
        cout << (double)(m) / (double)(k) << endl;
    }

    return 0;
}