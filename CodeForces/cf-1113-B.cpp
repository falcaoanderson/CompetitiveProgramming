/*
15/08/25 

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
#define sz(x) (int)(x).size()

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
    
    vector<int> v(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());
    int resp = sum;
    for(int i=n-1; i>0; i--){
        int delta=0;
        
        for(int x=2; x<=v[i]; x++){
            if(v[i]%x==0){
                delta = min(delta, v[i]/x - v[i] + v[0]*x-v[0]);
            }
        }

        resp = min(resp, sum+delta);
    }
    cout << resp << endl;

    return 0;
}
