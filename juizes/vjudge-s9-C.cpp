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

ll gcd(ll a, ll b){
    if(a==0LL) return b;

    return gcd(b%a, a);
}

int main(){
    fast_io;

    ll x;
    cin >> x;
    
    ll resp = x, ar=1, br=x;

    for(ll a=1; a*a<=x; a++){
        ll b = x/a;

        if( (a*b)/gcd(a, b) == x && max(a, b)<resp){
            resp = max(a, b);
            ar = a;
            br = b;
        }
    }

    cout << ar << " " << br << endl;

    return 0;
}
