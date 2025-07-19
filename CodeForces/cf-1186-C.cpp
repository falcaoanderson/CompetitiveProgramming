/*
18/07/25 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

int main(){
    fast_io;

    string a, b;
    cin >> a >> b;

    int sizea=a.size(), sizeb=b.size();
    int resp=0, crr=0;

    for(int i=0; i<sizeb; i++){
        crr ^= (a[i] != b[i]);
    }
    resp += (crr==0);
    
    for(int i=sizeb; i<sizea; i++){
        crr ^= (a[i-sizeb]!=a[i]);
        resp += (crr==0);
    }
    cout << resp << endl;

    return 0;
}
