// 10/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (2e5) + 10;

int pai[MAXN], peso[MAXN];

int find(int u){
    if(pai[u]==u) return u;

    return pai[u] = find(pai[u]);
}
void join(int a, int b){
    a = find(a);
    b = find(b);

    if(a==b) return;

    if(peso[a]==peso[b]){
        pai[b] = a;
        peso[a]++;
    }
    else if(peso[a]>peso[b]){
        pai[b] = a;
    }
    else{
        pai[a] = b;
    }
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;

    vector<piii> edge(m);

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        edge[i] = {c, a, b};
    }
    
    sort(edge.begin(), edge.end());
    for(int i=1; i<=n; i++) pai[i] = i;

    ll resp = 0LL;

    for(auto e: edge){
        int a, b, c;
        tie(c, a, b) = e;

        if(find(a)!=find(b)){
            join(a, b);
            resp += (ll) c;
        }
    }

    int a = find(1);
    for(int i=2; i<=n; i++){
        if(find(i)!=a){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << resp << endl;

    return 0;
}
