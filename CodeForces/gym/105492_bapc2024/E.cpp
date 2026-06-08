/*
24/01/26

*/

#include <bits/stdc++.h>

using namespace std;

// #define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)
// #define endl "\n"
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
int main(){
    // fast_io;

    int n;
    cin >> n;

    int low, high;
    cout << "? " << 1 << endl;
    cin >> low;
    cout << "? " << n << endl;
    cin >> high;

    int goal = (low+high) / 2;

    int l=2, r=n-1, best = INF, resp = -1;
    while(l<=r){
        int mid = (l+r) / 2;
        int crr;

        cout << "? " << mid << endl;
        cin >> crr;

        if(abs(crr-goal) < abs(best-goal)){
            best = crr;
            resp = mid; 
        }

        if(crr == goal){
            break;
        }
        else if(crr < goal){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout << "! " << 1 << " " << n << " " << resp << endl;

    return 0;
}