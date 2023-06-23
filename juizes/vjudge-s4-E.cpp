// 23/06/23 //
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

    int t;
    cin >> t;

    while(t--){
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;

        if(h<c){
            swap(p, f);
            swap(h, c);
        }

        int q = min(b/2, p);

        cout << q*h + max(min(b/2-q, f), 0) * c << endl;
    }

    return 0;
}
