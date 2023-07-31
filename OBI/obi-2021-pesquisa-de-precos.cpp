// 31/07/23 //
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

    bool flag = 1;

    while(n--){
        string uf;
        double a, g;

        cin >> uf >> a >> g;

        if(a*10.0 <= g*7.0){
            cout << uf << endl;
            flag = 0;
        }
    }

    if(flag) cout << "*" << endl;

    return 0;
}
