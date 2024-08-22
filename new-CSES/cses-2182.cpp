/*
22/08/24 
Problem: 
Complexity:
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
const int MAXN = (1e5) + 5;
const ll MOD  = (1e9) + 7;

ll n, p[MAXN], alpha[MAXN];
ll prefix[MAXN], sufix[MAXN];

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

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i] >> alpha[i];
    }
    
    ll divsum = 1, divqnt=1, divprod=1;
    prefix[0] = sufix[n+1] = 1;

    for(int i=1; i<=n; i++){
        divqnt = (divqnt * (alpha[i]+1LL))%MOD;
        
        prefix[i] = (prefix[i-1] * (alpha[i]+1LL))%(MOD-1LL);
        sufix[n-i+1] = (sufix[n-i+2] * (alpha[n-i+1]+1LL))%(MOD-1LL);


        divsum = ( divsum * ( ( (exp(p[i], alpha[i]+1LL)-1LL+MOD)*exp(p[i]-1LL, MOD-2LL) )%MOD ) )%MOD;
    }    

    for(int i=1; i<=n; i++){
        divprod = divprod * exp(p[i], ((((alpha[i] * (alpha[i]+1LL))/2LL)%(MOD-1LL)) * ((prefix[i-1] * sufix[i+1])%(MOD-1LL)))%(MOD-1LL) );
        divprod %= MOD;
    }


    cout << divqnt << " " << divsum << " " << divprod << endl;

    return 0;
}
