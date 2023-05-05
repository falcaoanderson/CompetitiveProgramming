// 05/05/23 //
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
int query(int i){
    int sum=0;
    while(i>=1){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
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

        int l=1, r=n, mid, ind=0;

        while(l<=r){
            mid = (l+r)/2;

            if(query(mid)>=p){
                ind = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        update(ind, -1);

        cout << v[ind] << " ";
    }
    cout << endl;

    return 0;
}
