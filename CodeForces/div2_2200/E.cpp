/*
27/02/26 

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define SZ(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int first_prime(int x){
    if(x<=2) return x;
    for(int i=2; i*i<=x; i++){
        if((x % i) == 0){
            return i;
        }
    }
    return x;
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    bool flag1 = 1, flag2 = 1;
    int prev = 0;
    
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i] < prev) flag1 = 0;
        prev = v[i];

        int aux = first_prime(v[i]);
        while(v[i] > 1 && (v[i] % aux) == 0){
            v[i] /= aux;
        }

        if(v[i] != 1){
            flag2 = 0;
        }
        else{
            v[i] = aux;
        }

    }

    if(flag1){
        cout << "Bob" << endl;
    }
    else if(flag2){
        bool flag = 1;
        for(int i=1; i<n; i++){
            if(v[i]<v[i-1]) flag = 0;
        }
        cout << (flag? "Bob": "Alice") << endl;
    }
    else{
        cout << "Alice" << endl;
    }
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
