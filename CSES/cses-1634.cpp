// 31/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e2) + 10;
const int MAXV = (1e6) + 10;

int memo[MAXV];

int main(){
    fast_io;

    int n, x;
    cin >> n >> x;

    vector<int> coin(n+1);
    for(int i=1; i<=n; i++) cin >> coin[i];

        
    for(int j=1; j<=x; j++){ 
        for(int i=1; i<=n; i++){ 
            if(i==1) memo[j] = INF;
            
            if(j-coin[i]>=0)
                memo[j] = min(memo[j], memo[j-coin[i]] + 1);
        }
    }
    
    cout << (memo[x]<INF?memo[x]:-1) << endl;

    return 0;
}
