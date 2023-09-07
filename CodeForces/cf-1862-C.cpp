// 07/09/23 //
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

void solve(){
    int n;
    cin >> n;

    vector<int> v(n+1), nv;
    bool flag = true;

    for(int i=1; i<=n; i++){
        cin >> v[i];

        if(!flag) continue;
        if(v[i]>n || (int)nv.size()>n){
            flag = false;
            continue;
        }

        if(i>1 && v[i]!=v[i-1]){
            int aux = v[i-1]-v[i];
            
            while(aux--){
                nv.PB(i-1);
            }
        }
    }
    if(!flag){
        cout << "NO" << endl;
        return;
    }
    int aux = v[n];
    while(aux--){
        nv.PB(n);
    }

    for(int i=1; i<=n; i++){
        if(v[i]!=nv[n-i]) flag = false;
    }

    cout << (flag? "YES": "NO") << endl;
}

int main(){
    fast_io;

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
