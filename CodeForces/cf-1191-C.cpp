/*
15/07/25 

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

int main(){
    fast_io;

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(m);
    for(int i=0; i<m; i++){
        cin >> v[i];
    }

    int resp=0;
    ll page_limit=0, page_count=0;
    
    for(int i=0; i<m; i++){
        if(v[i]<=page_limit){
            page_count++;
        }
        else{
            if(page_count>0){
                page_limit+=page_count;
                resp++;
            }    
            page_count=1;

            if(v[i]>page_limit) 
                page_limit += k * ((v[i]-page_limit+k-1LL)/k);
        }
    }
    resp++;

    cout << resp << endl;

    return 0;
}
