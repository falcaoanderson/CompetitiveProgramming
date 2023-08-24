// 24/08/23 //
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

    int a, n, m;
    cin >> a >> n >> m;

    int resp=-1, crr=0;
    for(int i=n; i>=1; i--){
        crr=0;
        for(int j=0; j<m; j++){
            bool val;
            cin >> val;

            crr = (val? 0: crr+1);

            if(crr>=a) resp = i;
        }
    }

    cout << resp << endl;

    return 0;
}
