/*
21/07/25 
04/11/25

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
#define debug(x) cout << #x << ": " << x << "\n"
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (5e5) + 5;
const int MOD  = (1e9) + 7;

int n, m;
int bit[MAXN];

int sum(int pos){
    int sum=0;
    while(pos>0){
        sum += bit[pos];
        pos -= (pos&-pos);
    }
    return sum;
}
void update(int pos){
    while(pos<=m){
        bit[pos] += 1;
        pos += (pos&-pos);
    }
}
int query(int val){
    int resp = -2, l=1, r=m, mid;
    
    while(l<=r){
        mid = (l+r)/2;
        int aux = sum(mid);

        if(aux==val){
            resp = mid;
            r = mid-1;
        }
        else if(aux<val){
            l = mid+1;
        }
        else{
            r= mid-1;
        }
    }

    return resp;
}

int main(){
    fast_io;

    int q;
    cin >> n >> m >> q;

    vector<pii> freq(m+1);

    for(int i=0; i<n; i++){
        int val;
        cin >> val;

        freq[val].FF++;
    }
    for(int i=1; i<=m; i++){
        freq[i].SS = i;
    }
    sort(freq.begin(), freq.end());

    vector< pair<ll, int> > queries(q);
    for(int i=0; i<q; i++){
        cin >> queries[i].FF;
        queries[i].FF -= (ll)(n);
        queries[i].SS = i;
    }
    sort(queries.begin(), queries.end());

    ll crr_time = 0;
    int it_queries = 0;

    update(freq[1].SS);
    for(int i=2; i<=m && it_queries<q; i++){
        if(freq[i].FF == freq[i-1].FF){
            update(freq[i].SS);
            continue;
        }

        ll delta_time = (ll)(freq[i].FF - freq[i-1].FF) * (ll)(i - 1);

        while(it_queries<q &&  queries[it_queries].FF <= crr_time + delta_time){
            int id = queries[it_queries].SS;
            ll qtime = queries[it_queries].FF;
            int iesimo = (qtime-crr_time-1LL) % (ll)(i-1) + 1LL; 
            
            queries[it_queries].FF = id;
            queries[it_queries].SS = query(iesimo);

            it_queries++;
        }

        crr_time += delta_time;
        update(freq[i].SS);
    }

    while(it_queries<q){
        int id = queries[it_queries].SS;
        ll qtime = queries[it_queries].FF;
        int iesimo = (qtime-crr_time-1LL) % (ll)(m) + 1LL; 

        queries[it_queries].FF = id;
        queries[it_queries].SS = query(iesimo);

        it_queries++;
    }

    sort(queries.begin(), queries.end());
    for(int i=0; i<q; i++){
        cout << queries[i].SS << endl;
    }

    return 0;
}
