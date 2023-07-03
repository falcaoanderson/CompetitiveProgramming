// 02/07/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int MAXN = 500+5;

int pai[MAXN], dist[MAXN];

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(pai[u]==pai[v]) return;

    if(dist[u]<dist[v]){
        pai[u] = v;
    }
    else{
        pai[v] = u;

        if(dist[u]==dist[v]) dist[u]++;
    }
}

int main(){
    fast_io;
    
    int N;
    cin >> N;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    
    while(N--){
        int s, p;
        cin >> s >> p;

        vector<pii> coords(p);
        for(int i=0; i<p; i++){
            cin >> coords[i].ff >> coords[i].ss;
        }

        vector<tiii> edges;
        for(int i=0; i<p; i++){
            for(int j=i+1; j<p; j++){
                int d = (coords[i].ff-coords[j].ff)*(coords[i].ff-coords[j].ff) + (coords[i].ss-coords[j].ss)*(coords[i].ss-coords[j].ss);
                
                edges.EB(d, i, j);
            }
        }

        sort(edges.begin(), edges.end());
        for(int i=0; i<p; i++){
            pai[i]=i;
            dist[i]=0;
        }

        int count = 0;
        double resp = 0.0;
        
        for(tiii edge: edges){
            int d, u, v;
            tie(d, u, v) = edge;

            if(find(u)==find(v)) continue;

            join(u, v);
            count++;

            if(count==p-1-(s-1)){
                resp = d;
                break;
            }
        }
        
        resp = sqrt(resp);
        cout << resp << endl;
    }

    return 0;
}
