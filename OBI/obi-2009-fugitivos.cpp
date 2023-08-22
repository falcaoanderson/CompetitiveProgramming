// 22/08/23 //
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

    int n; ll dist;
    cin >> n >> dist;

    dist *= dist;
    ll x=0, y=0;
    bool resp = 0;

    while(n--){
        char dir; ll d;
        cin >> dir >> d;

        if(dir=='N') y+=d;
        if(dir=='S') y-=d;
        if(dir=='O') x-=d;
        if(dir=='L') x+=d;

        if(x*x+y*y>dist) resp = 1;
    }

    cout << resp << endl;

    return 0;
}
