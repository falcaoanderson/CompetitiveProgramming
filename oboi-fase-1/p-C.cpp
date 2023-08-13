// 13/08/23 //
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

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<ll> v(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];

    int l=1, r=n;
    ll resp = 0;

    while(l<r){
        if(v[l]==v[r]){
            resp += v[l] + (l+1==r? 0LL: 2LL);
            l++;
            r--;
        }
        else if(v[l]>v[r]){
            v[l] -= v[r];
            resp += v[r] + 1LL;
            r--;
        }
        else{ // v[l] < v[r]
            v[r] -= v[l];
            resp += v[l]+1LL;
            l++;
        }
    }

    if(l==r){
        if(v[l]&1LL){
            cout << -1 << endl;
        }
        else{
            cout << resp + v[l]/2LL << endl;
        }
    }
    else{
        cout << resp << endl;
    }

    return 0;
}
