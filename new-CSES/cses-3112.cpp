/*
11/09/25 

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
    // fast_io;

    int l=1, r=1e9, resp=-1;
    while(l<=r){
        int mid = (l+r)/2;

        cout << "? " << mid << endl;
        string op;
        cin >> op;

        if(op=="YES"){
            l = mid+1;
        }
        else{
            resp = mid;
            r = mid-1;
        }
    }

    cout << "! " << resp << endl;

    return 0;
}
