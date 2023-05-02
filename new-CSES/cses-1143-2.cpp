// 02/05/23 // segment tree // O(n * log(n) + q * log(n) )
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

struct Node{
    int val, pos;
    
    Node(){}
    Node(int val_, int pos_){
        val = val_;
        pos = pos_;
    }
};

Node max(Node a, Node b){
    if(a.val>b.val || (a.val==b.val && a.pos<b.pos)) return a;
    return b;
}

int n, q;
ll v[MAXN];
Node seg[3*MAXN]; 

void build(int node, int i, int j){
    if(i==j){
        seg[node].val = v[i];
        seg[node].pos = i;
        return;
    }   
 
    int mid = (i+j)/2, left=2*node, right=2*node+1;
    
    build(left, i, mid);
    build(right, mid+1, j);
 
    seg[node] = max(seg[left], seg[right]);
}
 
Node query(int node, int i, int j, int x, int y){
    if(x<=i && j<=y) return seg[node];
    
    else if(j<x || y<i) return Node(-INF, INF);
    
    int mid = (i+j)/2, left=2*node, right=2*node+1;
 
    return max(query(left, i, mid, x, y), query(right, mid+1, j, x, y));
}
 
void update(int node, int i, int j, int k, int u){
    if(i==j){
        seg[node].val += u;
        return;
    }
    
    int mid = (i+j)/2, left=2*node, right=2*node+1;
 
    if(k <= mid){
        update(left, i, mid, k, u);
    }
    else{
        update(right, mid+1, j, k, u);
    }
 
    seg[node] = max(seg[left], seg[right]);
}

int main(){
    fast_io;
 
    cin >> n >> q;
 
    for(int i=1; i<=n; i++) cin >> v[i];
 
    build(1, 1, n);
 
    while(q--){
        int rooms;
        cin >> rooms;
        
        int node=1, l=1, r=n, mid;
        int resp = (seg[1].val>=rooms? seg[1].pos: -1);

        while(l<r){
            mid = (l+r)/2;
            
            if(seg[2*node].val>=rooms){
                node=2*node;
                r=mid;
            }
            else if(seg[2*node+1].val>=rooms){
                node=2*node+1;
                l=mid+1;
            }
            else{
                break;
            }

            resp = seg[node].pos; 
        }

        if(resp==-1){
            cout << 0 << " ";
        }
        else{
            cout << resp << " ";

            update(1, 1, n, resp, -rooms);
        }
    }
    cout << endl;

    return 0;
}