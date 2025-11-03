/*
06/10/25 

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

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;
    
    int n, m;
    cin >> n >> m;
    
    vector<int> freq(101);
    int total = 0;

    for(int i=0; i<n; i++){
        int t;
        cin >> t;

        int free_time = m-total;
        int resp = 0;

        for(int j=100; j>=1 && free_time<t; j--){
            if(free_time+j*freq[j]<t){
                resp      += freq[j];
                free_time += j*freq[j];
            }
            else{
                int aux = (t-free_time + j - 1) / j;

                resp += aux;
                free_time += j*aux;
            }
        }

        cout << resp << " ";

        freq[t]++;
        total += t;
    }
    cout << endl;

    return 0;
}
