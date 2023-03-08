// 04/11/20 // 12:18 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int n, m, pai[MAXN], peso[MAXN];

int find(int a){
    if(pai[a]==a) return a;

    return pai[a] = find(pai[a]);
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
    else if(peso[a]<peso[b]){
        pai[a] = b;
    }
}

int main(){
    fast_io;

    cin >> n >> m;
    
    for(int i=1; i<=n; i++) pai[i] = i;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        join(a, b);
    }

    vector<pii> arestas;

    for(int i=2; i<=n; i++){
        if(find(1)!=find(i)){
            join(1, i);
            arestas.pb(mp(1, i));
        }
    }

    cout << arestas.size() << endl;
    for(pii i: arestas)
        cout << i.first << " " << i.second << endl;

    return 0;
}
