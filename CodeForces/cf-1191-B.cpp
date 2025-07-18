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

    vector<int> v(3);
    for(int i=0; i<3; i++){
        string s;
        cin >> s;

        v[i] = (s[0]-'0') + 10*(s[1]=='m'? 0: (s[1]=='p'? 1: 2)); 
    }
    sort(v.begin(), v.end());
    
    if(v[0]==v[1]){
        if(v[1]==v[2]){
            cout << 0 << endl;
        } 
        else{
            cout << 1 << endl;
        }
    }
    else if(v[1]==v[2]){
        cout << 1 << endl;
    }
    else if(v[0]+1==v[1]){
        if(v[1]+1==v[2]){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    else if(v[1]+1==v[2]){
        cout << 1 << endl;
    }
    else if((v[0]+2==v[1] && v[0]%10!=9) ||
     (v[1]+2==v[2] && v[1]%10!=9)){
    
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }
    
    return 0;
}
