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

    ll n, m;
    cin >> n >> m;
    
    cout << (m-n%m) * ((n/m) * ((n/m) - 1)) / 2LL + 
    (n%m) * ((n/m + 1) * ((n/m + 1) - 1)) / 2LL   
    << " " 
    << ((n-m+1) * ((n-m+1) - 1)) / 2LL << endl;

    return 0;
}