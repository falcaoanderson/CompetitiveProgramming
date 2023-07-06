// 06/07/23 //
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

const int MAXN = (1<<17) + 5;

int pot[17+5];
int v[MAXN], seg[3*MAXN];

int log2(int x){
    for(int i=0; i<=17; i++) if((1<<i)==x) return i;
    return -1;
}

void build(int node, int i, int j){
    if(i==j){
        seg[node] = v[i];
        return;
    }
    
    int left=2*node, right=2*node+1, mid=(i+j)/2;
    build(left, i, mid); build(right, mid+1, j);
    
    if(log2(j-i+1)&1) seg[node] = seg[left]|seg[right];
    else              seg[node] = seg[left]^seg[right];
}

void update(int node, int i, int j, int pos, int val){
    if(i==j){
        seg[node] = val;
        return;
    }

    int left=2*node, right=2*node+1, mid=(i+j)/2;

    if(pos<=mid) update( left,     i, mid, pos, val);
    else         update(right, mid+1,   j, pos, val);

    if(log2(j-i+1)&1) seg[node] = seg[left]|seg[right];
    else              seg[node] = seg[left]^seg[right];
}

int main(){
    fast_io;

    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=(1<<n); i++) cin >> v[i];

    build(1, 1, (1<<n));
    
    while(m--){
        int pos, val;
        cin >> pos >> val;

        update(1, 1, (1<<n), pos, val);

        cout << seg[1] << endl;
    }

    return 0;
}
