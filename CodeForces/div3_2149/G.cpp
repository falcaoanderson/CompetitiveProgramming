/*
21/10/25 

*/

#include <bits/stdc++.h>
#include <random>
#include <chrono>
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

void solve(mt19937& rng){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    map<int, int> mapvals;
    vector<int> revmap;
    int aux=0;
    vector< vector<int> > v_idxs;

    for(int i=0; i<n; i++){
        cin >> v[i];
        
        if(mapvals.find(v[i])==mapvals.end()){
            mapvals[v[i]] = aux;
            v_idxs.PB(vector<int>());          
            revmap.PB(v[i]);
            v[i] = aux;

            aux++;
        }
        else{
            v[i] = mapvals[v[i]];
        }

        v_idxs[v[i]].PB(i);
    }


    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;

        uniform_int_distribution<int> unif(a, b); 

        vector<int> candidates;
        for(int i=0; i<50; i++){
            int idx = unif(rng);

            candidates.PB(v[idx]);
        }

        set<int> resp;

        for(int x: candidates){
            vector<int>& idxs = v_idxs[x];

            auto st = lower_bound(idxs.begin(), idxs.end(), a);
            auto ed = upper_bound(idxs.begin(), idxs.end(), b);

            if(st < ed && (int)(ed-st)>(b-a+1)/3) resp.insert(revmap[x]);
        }

        if(resp.empty()){
            cout << -1 << endl;
        }   
        else{
            for(int x: resp) cout << x << " ";
            cout << endl;
        }
    }
}

int main(){
    fast_io;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int t;
    cin >> t;

    while(t--){
        solve(rng);
    }

    return 0;
}
