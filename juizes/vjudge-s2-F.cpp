// 08/06/23 // brute-force (nao passa)
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

const int MAXN = 2e5+5;

bool visited[MAXN];

int main(){
    fast_io;

    int t;
    cin >> t;
    
    vector<pii> edges;
    
    while(t--){
        int n;
        cin >> n;

        edges.clear();

        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;

            edges.EB(u, v);
        }

        memset(visited, 0, sizeof(visited));

        visited[1] = 1;
        int resp = 0, qnt=1;

        while(qnt<n){
            for(pii edge: edges){
                int u, v;
                u = edge.ff;
                v = edge.ss;

                if(visited[u]^visited[v]){
                    visited[u] = visited[v] = 1;
                    qnt++;
                }
            }

            resp++;
        }

        cout << resp << endl;
    }

    return 0;
}