// 30/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> prefix(n+1);

    for(int i=1; i<=n; i++){
        ll val;
        cin >> val;
        prefix[i] = prefix[i-1] + val;
    }   

    ll resp = -INF;
    multiset<ll> menores;

    for(int i=a; i<=n; i++){
        menores.insert(prefix[i-a]);
        if(i>b) menores.erase(menores.find(prefix[i-b-1]));

        ll menor = *menores.begin();

        //for(int j=i-b; j<=i-a; j++)       menor no intervalo [i-b, i-a];
        //    menor = min(menor, prefix[j]);
        
        resp = max(resp, prefix[i] - menor);
    }

    cout << resp << endl;

    return 0;
}
