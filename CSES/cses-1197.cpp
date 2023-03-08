// 06/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const ll INF  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2510;
const int MAXM = 5010;

int n, m, ant[MAXN];
ll dist[MAXM];
vector< tuple<int, int, ll> > edge;

int main(){
    fast_io;

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;

        edge.pb({a, b, c});
    }    

    for(int i=1; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    int ini;

    for(int i=1; i<=n; i++){
        ini = -1;
        for(auto e: edge){
            int a, b; ll c;
            tie(a, b, c) = e;

            if(dist[b]>dist[a]+c){
                dist[b] = dist[a] + c;
                ant[b] = a;
                ini = b; 
            }
        }

        if(ini==-1) break;
    }
    
    if(ini==-1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        
        for(int i=0; i<n; i++) ini = ant[ini];

        stack<int> resp;
        int u = ant[ini];
        resp.push(ini);
        while(u!=ini){
             resp.push(u);
             u = ant[u];
        }
        resp.push(ini);

        while(!resp.empty()){
            cout << resp.top() << " ";
            resp.pop();
        }
        cout << endl;
    }
    
    return 0;
}
