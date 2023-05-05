// 05/05/23 // binary search over a fenwick tree
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

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = (2e5) + 5;

int n;
int bit[MAXN];

void update(int i, int u){
    while(i<=n){
        bit[i] += u;
        i += (i&-i);
    }
}
int bsearch(int val){
    int i=0;
    
    for(int p=18; p>=0 && val>0; p--){
        if( i+(1<<p)<=n && val-bit[i+(1<<p)]>0){
            i += (1<<p);
            val -= bit[i];
        }
    }

    return i+1;
}

int main(){
    fast_io;

    cin >> n;

    vector<int> v(n+1);

    for(int i=1; i<=n; i++) cin >> v[i];

    for(int i=1; i<=n; i++){
        bit[i] = (i&-i);
    }

    for(int i=1; i<=n; i++){
        int p;
        cin >> p;

        int ind = bsearch(p);
        update(ind, -1);

        cout << v[ind] << " ";
    }
    cout << endl;

    return 0;
}
