// 26/07/23 //
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

ll is_square(ll n){
    ll l=1LL, r=n, mid;

    while(l<=r){
        mid = (l+r)/2LL;

        if(mid*mid==n) return mid;
        else if(mid*mid>n){
            r=mid-1LL;
        }
        else{
            l=mid+1LL;
        }
    }

    return 0LL;
}

int main(){
    fast_io;

    ll d;
    cin >> d;

    for(ll i=0; i<=d; i++){
        ll j = is_square(d+i*i);

        if(j!=0LL){
            cout << i << " " << j << endl;
            return 0;     
        }
    }

    cout << "impossible" << endl;

    return 0;
}
