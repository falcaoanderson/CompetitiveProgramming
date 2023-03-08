// 10/11/20 // 6:03 PM //

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
const int MAXN = (2e5) + 10;

int n, q, prox[MAXN][30];

int main(){
    fast_io;
    
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> prox[i][0];
    
    for(int k=1; k<=29; k++)
        for(int i=1; i<=n; i++)
            prox[i][k] = prox[ prox[i][k-1] ][k-1];     // 2^(k-1) + 2^(k-1) = 2^k
    
    while(q--){
        int u, k;
        cin >> u >> k;

        while(k>0){
            int lsb = k&-k;
            
            int pos;
            for(int i=0; i<=29; i++) 
                if((1<<i)==lsb){
                    pos=i;
                    break;
                }

            u = prox[u][pos];
            k -= lsb;
        }

        cout << u << endl;
    }
    
    return 0;
}
