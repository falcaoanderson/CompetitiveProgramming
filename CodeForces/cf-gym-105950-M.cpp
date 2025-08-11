/*
09/08/25 

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

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> h(n+1);
    for(int i=1; i<=n; i++){
        int step;
        cin >> step;

        h[i] = h[i-1]+step;
    }
    
    int k;
    cin >> k;
    int top = (k==1?2:1);
    for(int i=1; i<=n; i++){
        if(i!=k && h[top]<h[i]) top = i;
    }

    if(h[top]+a>=h[k]+b){
        cout << "SIM" << endl;
        cout << top << endl;
    }
    else{
        cout << "NAO" << endl;
    }

    return 0;
}
