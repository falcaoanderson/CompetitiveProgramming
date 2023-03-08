// 31/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<ll, ll> pii;

struct MinQueue{
    deque<pii> dq;
    ll l=1LL, r=1LL; // tempo de tras, tempo da frente

    void init(){
        l = r = 1LL;
        dq.clear();
    }
    void push(ll val){
        while(!dq.empty() && dq.back().first>=val) dq.pop_back();

        dq.push_back(mp(val, l++));
    }
    void pop(){
        if(!dq.empty() && dq.front().second==r) dq.pop_front();
        r++;
    }
    ll getMin(){
        return dq.front().first;
    }
};


const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;

    int n, a, b;
    cin >> n >> a >> b;
    
    vector<ll> prefix(n+1);

    for(int i=1; i<=n; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    MinQueue fila;
    ll resp = -INF;

    for(int i=a; i<=n; i++){
        fila.push(prefix[i-a]);
        if(i>b) fila.pop();

        resp = max(resp, prefix[i]-fila.getMin());
    }

    cout << resp << endl;

    return 0;
}
