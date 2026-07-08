/*
16/05/26 

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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int n, value[MAXN * MAXN], node_left[MAXN * MAXN], node_right[MAXN * MAXN];

int query(int node){
    if(value[node] != -1) return value[node];

    cout << "? " << node << endl;
    int x;
    cin >> x;
    return x;
}
void answer(int node){
    cout << "! " << node << endl;
}

int flayer(int l){
    return 1 + ((l-1) * l) / 2;
}
int elayer(int l){
    return (l * (l+1)) / 2;
}
bool is_layer(int node, int l){
    return flayer(l) <= node && node <= elayer(l);
}

int log2(int x){
    int a = 0;
    while((1 << (a+1)) <= x) a++;
    return a;
}

void solve2(int start_node, int end_node){
    vector<int> nodes;
    int crr = start_node;
    while(crr < end_node){
        nodes.PB(crr);
        crr = node_left[crr];
    }

    int l = 1, r = SZ(nodes)-1, resp = -1;
    while(l <= r){
        int mid = (l+r) / 2;

        if(query(nodes[mid]) == 1){
            l = mid + 1;
            resp = nodes[mid];
        }
        else{
            r = mid - 1;
            resp = nodes[mid - 1];
        }
    }

    answer(resp);
}

void solve1(int root, int node){    
    if(is_layer(root, n+1)){
        answer(root);
        return;
    }
    if(is_layer(node, n+2)){
        solve2(root, node - 1);
        return;
    }

    if(query(node) == 1){
        solve1(node, node_right[node]);
    }
    else{
        solve1(root, node_left[node]);
    }
}

int main(){
    cin >> n;
    
    memset(value, -1, sizeof(value));
    
    value[1] = 1;
    for(int i=flayer(n+2); i<=elayer(n+2); i++) value[i] = 0;
    
    for(int l=1; l<=n+1; l++){
        int a = flayer(l), b = elayer(l);
        for(int i=a; i<=b; i++){
            node_left[i] = b + i - a + 1;
            node_right[i] = b + i - a + 2;
        }
    }

    solve1(1, 3);

    return 0;
}
