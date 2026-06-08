/*
24/01/26

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

    double m, n, r;
    cin >> m >> n >> r;

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double alpha = 2.0 * acos(0) * (abs(x1 - x2) / m);
    double resp = 1e9;
    for(int i=0; i<=n; i++){
        double y = i;
        double a = r * ((abs(y1-y) + abs(y2-y)) / n);
        double b = r * (y/n) * alpha; 
        
        // cout << a << " " << b << " " << a + b << endl;
        resp = min(resp, a+b); 
    }
    
    cout.precision(9);
    cout.setf(ios::fixed);
    cout << resp << endl;

    return 0;
}