/*
08/03/24 
Problem: Atcoder abc291 - E: Find Permutation 
Complexity: O(mlogm + n)
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

int indegree[MAXN], outdegree[MAXN];
vector<int> adj[MAXN];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    set<pii> added_edges;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        if(added_edges.find({a, b})==added_edges.end()){

            adj[a].PB(b);
            indegree[b]++;
            outdegree[a]++;
        }
    }

    int menor=0;
    bool possible = 1;
    int aux = 0;
    vector<int> resp(n+1);

    for(int i=1; i<=n && possible; i++){
        if(indegree[i]==0){
            if(menor==0) menor = i;
            else         possible = 0;
        }
    }
    if(menor==0) possible = 0;

    while(possible){
        int u = menor;
        menor = 0;
        resp[u] = (++aux);

        if(aux==n) break;

        for(int v: adj[u]){
            indegree[v]--;

            if(indegree[v]==0){
                if(menor==0) menor = v;
                else         possible = 0;
            }
        }
        if(menor==0) possible = 0;
    }

    if(possible){
        cout << "Yes" << endl;
        for(int i=1; i<=n; i++) cout << resp[i] << " ";
        cout << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}
