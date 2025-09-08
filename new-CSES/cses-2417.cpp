/*
06/09/25 

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
const int MAXVAL = (1e6);
const int MAXN = (1e5) + 5;
const int MOD  = (1e9) + 7;

int crivo[MAXVAL+5], freq_factors[MAXVAL];
void init_crivo(){
    crivo[1] = 1;
    for(int i=2; i<=MAXVAL; i++){
        if(crivo[i]==0){
            for(int j=i; j<=MAXVAL; j+=i){
                crivo[j] = i;
            }
        }
    }
}

int main(){
    fast_io;

    int n;
    cin >> n;

    init_crivo();

    int new_n=0;
    ll resp = 0;
    vector<vector<int>> primes(n);

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
    
        if(val==1){
            resp++;
            continue;
        }

        while(val>1){
            int p = crivo[val];
            primes[new_n].PB(p);
         
            while(val%p==0) val /= p;
        }

        int qnt = SZ(primes[new_n]);
        for(int mask=1; mask<(1<<qnt); mask++){
            val = 1;
            for(int j=0; j<qnt; j++){
                if((mask&(1<<j)) != 0){
                    val *= primes[new_n][j];
                }
            }
            freq_factors[val]++;
        }

        new_n++;
    }

    resp = resp*(resp-1LL) + 2LL*resp*((ll)n-resp);

    for(int i=0; i<new_n; i++){
        int qnt = SZ(primes[i]);
        
        int coprimes = new_n-1;

        for(int mask=1; mask<(1<<qnt); mask++){
            int val = 1, crr=0;
            for(int j=0; j<qnt; j++){
                if((mask&(1<<j)) != 0){
                    crr++;
                    val *= primes[i][j];
                }
            }

            coprimes -= (crr&1? 1: -1) * (freq_factors[val]-1); 
        }

        resp += (ll)coprimes;
    }

    cout << resp/2LL << endl;

    return 0;
}
