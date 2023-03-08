// 27/10/20 // xx:xx PM //

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

ll mod(ll a){
    return (a>=0LL?a:-a);
}

int main(){
    fast_io;

    int n, k;
    cin >> n >> k;
    
    vector<ll> v(n+1);
    indexed_set wind;
    
    for(int i=1; i<=n; i++) cin >> v[i];

    for(int i=1; i<=k; i++) wind.insert(v[i]); // janela inicial
    
    int pos_med  = (k&1 ? k/2: k/2-1);

    ll custo = 0LL;
    ll med = *(wind.find_by_order(pos_med));

    for(int i=1; i<=k; i++) custo += mod(v[i] - med); // custo da janela inicial

    cout << custo << " ";

    for(int i=k+1; i<=n; i++){
        ll med_ant = med;

        wind.erase(wind.find_by_order(wind.order_of_key(v[i-k])));
        wind.insert(v[i]);

        med = *(wind.find_by_order(pos_med));

        custo += mod(v[i]-med) - mod(v[i-k]-med_ant);

        if(~k&1) custo -= (med-med_ant);

        cout << custo << " ";
    }

    cout << endl;

    return 0;
}
