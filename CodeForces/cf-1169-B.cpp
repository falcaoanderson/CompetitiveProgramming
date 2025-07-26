/*
25/07/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;
    
    vector<int> a(m), b(m);
    int idx = -1;

    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
        if(a[i]>b[i]) swap(a[i], b[i]);

        if(a[i]!=a[0] && a[i]!=b[0] && b[i]!=a[0] && b[i]!=b[0]){
            idx = i;
        }
    }
    if(idx==-1){
        cout << "YES" << endl;
        return 0;
    }    
    vector<int> aux = {a[0], b[0], a[idx], b[idx]};
    bool resp = 0;

    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            int x = aux[i], y=aux[j];
            
            bool flag = 1;
            for(int k=0; k<m && flag; k++){
                if(a[k]!=x && a[k]!=y && b[k]!=x && b[k]!=y){
                    flag = 0;
                }
            }

            if(flag){
                resp = 1;
                break;
            }
        }
        if(resp){
            break;
        }
    }

    cout << (resp?"YES":"NO") << endl;
    

    return 0;
}
