// 06/08/23 //
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

    int d, c, r;
    cin >> d >> c >> r;

    vector<int> v(c);
    for(int i=0; i<c; i++) cin >> v[i];

    int resp = r;
    while(r--){
        int val;
        cin >> val;

        d+=val;
    }

    for(int i=0; i<c && d>=v[i]; i++){
        resp++;
        d -= v[i];
    }   

    cout << resp << endl;

    return 0;
}
