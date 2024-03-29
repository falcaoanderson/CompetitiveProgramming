// 14/06/23 //
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

    int a, b, c;
    cin >> a >> b >> c;

    int n = a+b+c;
    vector<int> v(n);

    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    vector<int> resp;
    bool flag = true;
    for(int i=1; i<n; i++){
        if(v[i]==v[i-1] && flag){
            resp.PB(v[i]);
            flag = false;
        }

        if(v[i]!=v[i-1]) flag = true;
    }
    
    cout << resp.size() << endl;
    for(int i: resp) cout << i << endl;

    return 0;
}
