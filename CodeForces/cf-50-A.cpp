/*
02/09/25 

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

    int a, b;
    cin >> a >> b;
    
    if(a%2==0){
        cout << (a/2) * b << endl;
    }
    else if(b%2==0){
        cout << (b/2) * a << endl;
    }
    else{
        if(a>b) swap(a, b);
        
        cout << (b/2) * a + a/2 << endl;
    }
    
    return 0;
}
