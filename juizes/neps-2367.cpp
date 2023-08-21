// 21/08/23 //
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

    int n, e, d;
    cin >> n >> e >> d;

    int resp = 1e9;
    while(n--){
        int a, b;
        cin >> a >> b;

        resp = min(resp, abs(a-e)+abs(b-d));
    }

    cout << resp << endl;

    return 0;
}
