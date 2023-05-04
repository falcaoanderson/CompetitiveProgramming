// 04/05/23 // O(n + q * log(n))
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
ll bit[MAXN];

ll query(int i){
    ll sum = 0LL;   

    while(i>=1){
        sum += bit[i];
        i -= (i&-i);
    }

    return sum;
}

void update(int i, ll u){
    while(i<=n){
        bit[i] += u;
        i += (i&-i);
    }
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;

    vector<ll> dif(n+1), prefix(n+1);
    int crr, last=0;

    for(int i=1; i<=n; i++){
        cin >> crr;

        dif[i] = crr - last;
        last = crr;
    }

    // build fenwick tree
    for(int i=1; i<=n; i++){
        prefix[i] = prefix[i-1] + dif[i];

        bit[i] = prefix[i] - prefix[i - (i&-i)]; // soma do intervalo [i-(i&-1)+1, i]
    }

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int a, b, u;
            cin >> a >> b >> u;

            update(a, u);
            update(b+1, -u);
        }
        else{
            int k;
            cin >> k;

            cout << query(k) << endl;
        }
    }

    return 0;
}
