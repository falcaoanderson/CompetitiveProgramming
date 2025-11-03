/*
13/09/25 

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


int v[MAXN], perm[MAXN];

void mergesort(int l, int r){
    if(l>=r){
        return;
    }   

    int mid = (l+r)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);

    vector<int> aux(r-l+1);
    int pl=l, pr=mid+1, idx=0;

    while(idx<r-l+1){
        if(pl>mid){
            aux[idx++] = v[pr++];
            continue;
        }
        if(pr>r){
            aux[idx++] = v[pl++];
            continue;
        }


        cout << "? " << v[pl] << " " << v[pr] << endl; // a_{v[pl]} < a_{v[pr]} ?
        string op;
        cin >> op;

        if(op=="YES"){
            aux[idx++] = v[pl++];
        }
        else{
            aux[idx++] = v[pr++];
        }
    }

    for(int i=l; i<=r; i++){
        v[i] = aux[i-l];
    }
}

int main(){
    // fast_io;

    int n=1000;
    cin >> n;

    for(int i=1; i<=n; i++) v[i] = i;
    mergesort(1, n);
    
    for(int i=1; i<=n; i++){
        perm[v[i]] = i;
    }
    
    cout << "! ";
    for(int i=1; i<=n; i++) cout << perm[i] << " ";
    cout << endl;

    return 0;
}
