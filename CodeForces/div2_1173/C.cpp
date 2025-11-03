/*
26/10/25 

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
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
    }
    
    int last, maxv=0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        last = x;

        if(x>0){
            v[x] = i+1;
            maxv = max(maxv, i+1-x+1);
        }
    }
    
    bool flag = 1;
    for(int i=1; i<=last && flag; i++){
        flag = (v[i]==n-last+i);
    }
    for(int i=last+1; i<=n && flag; i++){
        flag = (v[i]<=i-last-1);
    }

    if(flag){
        cout << n - last << endl;
    }
    else{
        cout << n + maxv << endl;
    }

    return 0;
}
