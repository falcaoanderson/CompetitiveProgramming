// 17/07/23 //
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

    vector<ll> v;
    int resp=-1;

    for(int i=0; i<n; i++){
        ll val;
        cin >> val;

        if(resp!=-1 || i>100) continue;

        v.PB(val);
        sort(v.begin(), v.end());

        for(int j=2; j<=i; j++){
            if(v[j]<v[j-1]+v[j-2]){
                resp=i+1;
                break;
            }
        }
    }

    cout << resp << endl;

    return 0;
}
