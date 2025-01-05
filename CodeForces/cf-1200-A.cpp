/*
04/01/25 
CF 578 Div.2 A 
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

    vector<bool> room(10);
    int n;
    cin >> n;

    while(n--){
        char c;
        cin >> c;

        if('0'<=c && c<='9'){
            room[c-'0'] = 0;
        }
        else if(c=='L'){
            for(int i=0; i<10; i++){
                if(!room[i]){
                    room[i]=1;
                    break;
                }
            }
        }
        else{
            for(int i=9; i>=0; i--){
                if(!room[i]){
                    room[i]=1;
                    break;
                }
            }
        }
    }

    for(bool x: room) cout << x;
    cout << endl;

    return 0;
}
