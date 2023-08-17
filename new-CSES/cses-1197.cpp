// 17/08/23 // bellman-ford
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

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2500) + 5;

ll dist[MAXN];
int last[MAXN];

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<tiii> edges;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(a==b && c>=0) continue;

        edges.EB(a, b, c);
    }

    //for(int i=1; i<=n; i++) dist[i] = INF;
    int u=0;
    //dist[1] = 0;

    for(int sz=1; sz<=n ; sz++){
        u = 0;
        for(tiii edge: edges){
            int a, b, c;
            tie(a, b, c) = edge;

            if(dist[a]+(ll)c < dist[b]){
                dist[b] = dist[a]+(ll)c;
                last[b] = a;
                u = a;
            }
        }
        if(u==0) break;
    }

    if(u==0){ // nao possui ciclo negativo
        cout << "NO" << endl;
    }
    else{// possui ciclo negativo
    
        for(int i=0; i<n; i++) u = last[u]; // volto n vezes para garantir que u faz parte do ciclo
        
        stack<int> resp;
        int v = u;
        resp.push(u);
        while(last[v]!=u){
            v = last[v];
            resp.push(v);
        }    
        resp.push(u);

        cout << "YES" << endl;
        while(!resp.empty()){   
            cout << resp.top() << " ";
            resp.pop();
        }
        cout << endl;
    }
    
    return 0;
}