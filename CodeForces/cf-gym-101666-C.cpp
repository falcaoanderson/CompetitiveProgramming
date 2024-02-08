// 27/01/24 //
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
#include <functional>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    cin >> n;

    set<ll> resp, aux;
    queue<ll> fila;

    ll last=0;
    for(int i=0; i<n; i++){
        ll crr;
        cin >> crr;

        if(last==crr) continue;

        resp.insert(crr);

        int sz = fila.size();
        for(int j=0; j<sz; j++){
            ll a = fila.front(); 
            fila.pop(); aux.erase(a);

            a = __gcd(a, crr);
            resp.insert(a);

            if(a!=1 && aux.find(a)==aux.end()){
                fila.push(a);
                aux.insert(a);
            }
        }
        if(crr!=1 && aux.find(crr)==aux.end()){
                fila.push(crr);
                aux.insert(crr);
        }

        last = crr;
    }

    cout << resp.size() << endl;

    return 0;
}
