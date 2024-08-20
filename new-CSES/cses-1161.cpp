/*
19/08/24 
Problem: 
Complexity:
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
    
    int total, n;
    cin >> total >> n;

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        pq.push(val);
    }

    ll resp = 0;
    while(pq.size() >  1){
        ll aux = pq.top(); pq.pop();
        aux += pq.top(); pq.pop();

        resp += aux;
        pq.push(aux);
    }   
    cout << resp << endl;

    return 0;
}
