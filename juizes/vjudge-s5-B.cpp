// 03/07/23 //
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

ll solve(ll c, ll k){
    ll qnt = 0LL;

    while(c>k){
        c = c-k-((c-k)/10LL);
        qnt += k;
    }
    qnt += c;

    return qnt;
}

int main(){
    fast_io;

    ll c;
    cin >> c;

    ll l=1LL, r=c/2LL, mid, resp=1LL;

    while(l<=r){
        mid = (l+r)/2LL;

        if(solve(c, mid)>=(c+1LL)/2LL){
            resp = mid;
            r = mid-1LL;
        }
        else{
            l = mid+1LL;
        }
    }           

    cout << resp << endl;
    
    return 0;
}
