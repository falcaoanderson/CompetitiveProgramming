// 24/08/24 // Virtual
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1e2 + 5;

struct poly{
    int a, b, c;
    poly(){}
    poly(int _a, int _b, int _c){
        a = _a;
        b = _b;
        c = _c;
    }

    double eval(double t){
        return (double)(a)*t*t + (double)(b) * t + (double)c;
    }
};

typedef tuple<int, int, poly> tiip;
typedef pair<int, int> pii;

int n, m;

tiip edges[205];

int parent[MAXN], sz[MAXN];

int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void union_sets(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;

    if(sz[u]<sz[v]){
        swap(u, v);
    }
    parent[v] = u;
    sz[u]+=sz[v];
}

double minbyt(double t){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1;
    }

    vector< pair<double, pii> > e;

    for(int i=0; i<m; i++){
        int u, v; poly p;
        tie(u, v, p) = edges[i];

        e.push_back({ p.eval(t), {u, v}});
    }

    sort(e.begin(), e.end());
    
    double cost = 0;

    for(int i=0; i<m; i++){
        int u=e[i].second.first, v=e[i].second.second;

        if(find(u)!=find(v)){
            union_sets(u, v);
            cost += e[i].first;
        }
    }

    return cost;
}

double tern(double L, double R) {
    double eps = 1e-6;
    while(R-L> eps) {
        double m1 = L + (R-L)/3.0;
        double m2 = R - (R-L)/3.0;
        double f1 = minbyt(m1);
        double f2 = minbyt(m2);
        if (f1 < f2) R = m2;
        else L = m1;
    }
    return minbyt(L);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v, a, b, c;
        cin >> u >> v >> a >> b >> c;

        edges[i] = tiip(u, v, poly(a, b, c));
    }

    cout << setprecision(15) << fixed << tern(-1e6, 1e6) << endl;

    return 0;
}