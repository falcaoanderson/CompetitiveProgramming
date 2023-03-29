// 29/03/23 //
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
 
using namespace std;
 
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5;

int n, k;
ll v[MAXN+10], seg[4*MAXN+10];

inline ll min(ll a, ll b){
    return (a<b ? a : b);
}
inline ll max(ll a, ll b){
    return (a>b ? a : b);
}

void init(int no, int i, int j){
    int left = 2*no, right = 2*no+1, mid = (i+j)/2;
    
    if(i==j){
        seg[no] = v[i];
        return;
    }
    
    init( left,       i, mid);
    init(right, mid + 1,   j);

    seg[no] = min(seg[left], seg[right]);
}

ll query(int no, int x, int y, int i, int j){
    int left = 2*no, right = 2*no+1, mid = (i+j)/2;

    if(x<=i && j<=y){
        return seg[no];
    }
    if(j < x || y < i){
        return LLONG_MAX;
    }

    ll op1 = query( left, x, y,     i, mid);
    ll op2 = query(right, x, y, mid+1,   j);

    return min(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    
    init(1, 1, n);
    
    while(k--){
        int a, b;
        cin >> a >> b;

        cout << query(1, a, b, 1, n) << endl;
    }

    return 0;
}