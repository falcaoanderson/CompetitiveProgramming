// 28/10/20 // 3:00 PM //
 
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
    
    int n;
    ll t;
    cin >> n >> t;

    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    ll ini = 1, fim = t*v[0], resp=-1;
    
    while(ini<=fim){
        ll meio = (ini+fim)/2;
        ll qnt = 0;

        for(int i=0; i<n; i++){
            qnt += meio/v[i];
            if(qnt>=t) break;
        }
        
        if(qnt>=t){
            resp = meio;
            fim = meio-1;
        }
        else
            ini = meio+1;
    }
    
    cout << resp << endl;

    return 0;
}