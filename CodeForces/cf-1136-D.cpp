/*
07/08/25 

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
const int MAXN = (5e2) + 5;
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

    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    vector< vector<int> > adj(n+1);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].PB(b);
    }

    set<int> stay;
    stay.insert(p[n-1]);

    for(int i=n-2; i>=0; i--){
        int qnt=0;
        for(int x: adj[p[i]]){
            if(stay.find(x)!=stay.end()){
                qnt++;
            }
        }

        if(qnt!=(int)stay.size()){
            stay.insert(p[i]);
        }
    }

    cout << n - (int)stay.size() << endl;

    return 0;
}
