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

    string sw;
    int vw=0;

    while(n--){
        string s_crr;
        int v_crr;

        cin >> s_crr >> v_crr;

        if(v_crr>vw){
            vw = v_crr;
            sw = s_crr;
        }
    }

    cout << sw << endl << vw << endl;

    return 0;
}
