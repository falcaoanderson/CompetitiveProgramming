/*
22/10/25 

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

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int n, bit[MAXN];
int query(int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}
void update(int i, int val){
    while(i<=n){
        bit[i] += val;
        i += (i & -i);
    }
}

int main(){
    fast_io;

    int q;
    cin >> n >> q;
    
    int maxval = 0;
    map<int, int> compress;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];

        if(compress.find(v[i])==compress.end()){
            maxval++;
            compress[v[i]] = maxval;
            v[i] = maxval;
        }
        else{
            v[i] = compress[v[i]];
        }
    }

    vector< pair<pii, int> > queries(q);
    for(int i=0; i<q; i++){
        cin >> queries[i].FF.SS >> queries[i].FF.FF;
        queries[i].SS = i;
    }
    sort(queries.begin(), queries.end());

    int r = -1;
    vector<int> resp(q), last(maxval+1);
    for(int i=0; i<q; i++){
        int id = queries[i].SS, a = queries[i].FF.SS, b = queries[i].FF.FF;
        a--; b--; // 0 indexed
        
        while(r<b){
            r++;
         
            if(last[v[r]]!=0){
                update(last[v[r]], -1);
            }

            last[v[r]] = r+1;
            update(last[v[r]], 1);
        }

        resp[id] = query(b+1) - query(a);
    }

    for(int x: resp) cout << x << endl;

    return 0;
}
