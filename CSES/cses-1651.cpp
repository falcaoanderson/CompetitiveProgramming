// 14/11/20 // xx:xx PM //

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

int n, q, v[MAXN];
ll bit[MAXN];

void update(int i, ll val){
    while(i<=n){
        bit[i] += val;
        i += (i&-i);
    }
}
ll query(int i){
    ll sum = 0;
    while(i>0){
        sum += bit[i];
        i -= (i&-i);
    }
    return sum;
}

int main(){
    fast_io;
    
    cin >> n >> q;
    int ant = 0;
    for(int i=1; i<=n; i++){
        int val;
        cin >> val;
        
        update(i, val-ant);
        ant = val;
    }

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int a, b, c;
            cin >> a >> b >> c;

            update(a, c);
            update(b+1, -c);
        }
        else{
            int k;
            cin >> k;

            cout << query(k) << endl;
        }
    }



    return 0;
}
