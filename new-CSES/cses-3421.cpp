/*
26/08/25 

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

const ll MOD  = (1e9) + 7;

int main(){
    fast_io;
    
    ll n;
    cin >> n;

    map<int, int> freq;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;

        if(freq.find(x)==freq.end()){
            freq[x]=1;
        }
        else{
            freq[x]++;
        }
    }

    ll resp = 1;
    for(pii p: freq){
        resp = (resp * (p.SS+1LL))%MOD;
    }
    resp = (resp+MOD-1LL)%MOD;

    cout << resp << endl;

    return 0;
}
