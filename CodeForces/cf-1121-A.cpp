/*
10/08/25 

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
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> v(n), s_id(n), s_max(m);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    for(int i=0; i<n; i++){
        cin >> s_id[i];
        s_id[i]--;
        
        s_max[s_id[i]] = max(s_max[s_id[i]], v[i]);
    }
    
    int resp=0;
    for(int i=0; i<k; i++){
        int id;
        cin >> id;
        id--;
        
        if(s_max[s_id[id]] > v[id]){
            resp++;
        }
    }
    
    cout << resp << endl;

    return 0;
}