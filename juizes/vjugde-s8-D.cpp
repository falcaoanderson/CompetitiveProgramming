// 01/07/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;

void solve(){
    int n, x;
    cin >> n >> x;

    int d_max=0, saldo = -INF; 

    while(n--){
        int d, h;
        cin >> d >> h;

        d_max = max(d_max, d);
        saldo = max(saldo, d-h);
    }

    if(x<=d_max){
        cout << 1 << endl;
    }
    else if(saldo<=0){
        cout << -1 << endl;
    }
    else{
        int q = (x-d_max+saldo-1)/saldo;

        x =  x - saldo * q;

        if(x>0) q++;

        cout << q << endl;
    }
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
