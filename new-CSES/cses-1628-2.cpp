// 22/09/23 //
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
#include <functional>
#include <cmath>

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

int x;
void brute_force(vector<int> &v, vector<int> &qnt){
    int sz = v.size();

    for(int i=0; i<(1<<sz); i++){
        
        int crr = 0;
        for(int j=0; j<sz; j++){
            if((i&(1<<j))!=0){
                crr += v[j];

                if(crr>x) break;
            }
        }

        if(crr<=x) qnt.PB(crr);
    }

    if(qnt.empty()) qnt.PB(0);
    sort(qnt.begin(), qnt.end());
}

int main(){
    fast_io;

    int n;
    cin >> n >> x;

    vector<int> vl, vr;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        if(i<n/2 && val<=x) vl.PB(val);
        if(i>=n/2 && val<=x) vr.PB(val);
    }

    vector<int> qleft, qright;
    brute_force(vl, qleft);
    brute_force(vr, qright);

    ll resp = 0;

    for(int val: qleft){
        int l = lower_bound(qright.begin(), qright.end(), x-val) - qright.begin();
        int r = upper_bound(qright.begin(), qright.end(), x-val) - qright.begin();

        resp += (ll)(r-l); 
    }

    cout << resp << endl;

    return 0;
}
