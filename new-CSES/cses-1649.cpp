// 01/05/23 // segment tree
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
 
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define ll long long
 
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
 
const int INF  = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
 
int n, q;
ll v[MAXN], seg[3*MAXN]; 
 
void build(int node, int i, int j){
    if(i==j){
        seg[node] = v[i];
        return;
    }   
 
    int mid = (i+j)/2, left=2*node, right=2*node+1;
    
    build(left, i, mid);
    build(right, mid+1, j);
 
    seg[node] = min(seg[left], seg[right]);
}
 
ll query(int node, int i, int j, int x, int y){
    if(x<=i && j<=y) return seg[node];
    
    else if(j<x || y<i) return INF;
    
    int mid = (i+j)/2, left=2*node, right=2*node+1;
 
    return min(query(left, i, mid, x, y), query(right, mid+1, j, x, y));
}
 
void update(int node, int i, int j, int k, int u){
    if(i==j){
        seg[node] = u;
        return;
    }
    
    int mid = (i+j)/2, left=2*node, right=2*node+1;
 
    if(k <= mid){
        update(left, i, mid, k, u);
    }
    else{
        update(right, mid+1, j, k, u);
    }
 
    seg[node] = min(seg[left], seg[right]);
}
 
int main(){
    fast_io;
 
    cin >> n >> q;
 
    for(int i=1; i<=n; i++) cin >> v[i];
 
    build(1, 1, n);
 
    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        
        if(t==1){ //update
            update(1, 1, n, a, b);
        }
        else{ //query
            cout << query(1, 1, n, a, b) << endl;
        }
    }
 
    return 0;
}