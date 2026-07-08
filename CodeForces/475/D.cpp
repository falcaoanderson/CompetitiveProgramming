/*
07/02/26 

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
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int n;
int v[MAXN], igcd[4 * MAXN];
map<int, ll> prefix[4 * MAXN], sufix[4 * MAXN], interval[4 * MAXN]; 

int gcd(int a, int b){
    return (b? gcd(b, a % b): a);
}

void build(int node, int i, int j){
    if(i==j){
        igcd[node] = v[i];
        prefix[node][v[i]] = sufix[node][v[i]] = interval[node][v[i]] = 1;
        return;
    }
    int l = 2*node, r = 2*node+1;
    build(l, i, (i+j) / 2);
    build(r, (i+j) / 2 + 1, j);

    if(interval[l].size() < interval[r].size()){
        swap(interval[l], interval[r]);
    }

    swap(interval[node], interval[l]);
    for(auto& pr: interval[r]){
        interval[node][pr.FF] += pr.SS;
    }
    for(auto& pl: sufix[l]){
        for(auto& pr: prefix[r]){
            interval[node][gcd(pl.FF, pr.FF)] += pl.SS * pr.SS;
        }
    }

    swap(prefix[node], prefix[l]);
    swap(sufix[node], sufix[r]);
    for(auto& pr: prefix[r]){
        prefix[node][gcd(igcd[l], pr.FF)] += pr.SS;
    }
    for(auto& pl: sufix[l]){
        sufix[node][gcd(igcd[r], pl.FF)] += pl.SS;
    }

    igcd[node] = gcd(igcd[l], igcd[r]);
}

int main(){
    fast_io;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    
    build(1, 1, n);

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x;
        cin >> x;

        if(interval[1].find(x) != interval[1].end())
            cout << interval[1][x] << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
