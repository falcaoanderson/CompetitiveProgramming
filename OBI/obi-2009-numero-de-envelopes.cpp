// 07/08/23 //
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

int main(){
    fast_io;
    
    int n, k;
    cin >> n >> k;

    vector<int> v(k);

    while(n--){
        int val;
        cin >> val;

        v[val-1]++;
    }

    int resp = INF;
    for(int x: v){
        resp = min(resp, x);
    }

    cout << resp << endl;

    return 0;
}
