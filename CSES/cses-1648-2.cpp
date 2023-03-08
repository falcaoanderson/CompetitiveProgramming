// 11/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int n, q;
ll bit[MAXN], v[MAXN];

void update(int i, ll val){
    while(i<=n){
        bit[i] += val;
        i += (i&-i);
    }
}

ll query(int i){
    ll sum=0LL;
    while(i>0){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int main(){
    fast_io;
    
    cin >> n >> q;
    
    for(int i=1; i<=n; i++){
        cin >> v[i];

        update(i, v[i]);
    }

    while(q--){
        int op, a, b;
        cin >> op >> a >> b;

        if(op==1){
            update(a, b-v[a]);
            v[a] = b;
        }
        else{
            ll resp = query(b) - query(a-1);
            cout << resp << endl;
        }
    }

    return 0;
}
