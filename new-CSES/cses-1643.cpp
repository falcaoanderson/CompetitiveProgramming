// 29/03/23 //
//solucao bruta
#include <iostream>
#include <climits>
 
using namespace std;
 
#define endl "\n"

typedef long long ll;

const int MAXN = 2e5+5;

int n;
ll v[MAXN], seg[4*MAXN];

inline ll min(ll a, ll b){
    return (a<b ? a : b);
}
inline ll max(ll a, ll b){
    return (a>b ? a : b);
}

void build(int no, int i, int j){
    int left = 2*no, right = 2*no+1, mid = (i+j)/2;
    
    if(i==j){
        seg[no] = v[i];
        return;
    }
    
    build( left,       i, mid);
    build(right, mid + 1,   j);

    seg[no] = min(seg[left], seg[right]);
}

ll query(int no, int i, int j, int x, int y){
    int left = 2*no, right = 2*no+1, mid = (i+j)/2;

    if(x<=i && j<=y){
        return seg[no];
    }
    if(j < x || y < i){
        return LLONG_MAX;
    }

    ll op1 = query( left,     i, mid, x, y);
    ll op2 = query(right, mid+1,   j, x, y);

    return min(op1, op2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        v[i] += v[i-1];
    }
    
    build(1, 1, n);
    
    ll resp = v[1];

    for(int i=2; i<=n; i++){
        resp = max(resp, v[i] - min(query(1, 1, n, 1, i-1), 0LL));
    }

    cout << resp << endl;

    return 0;
}