// 03/08/23 //
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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7; 

int main(){
    fast_io;

    int n;
    cin >> n;

    vector<int> v(n+1);

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    int p;
    cin >> p;

    int total = 0;

    while(p--){
        int t;
        cin >> t;

        if(v[t]>0){
            total++;
            v[t]--;
        }
    }

    cout << total << endl;

    return 0;
}