// 17/11/20 // xx:xx PM //

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
const int MAXN = (1e6) + 10;
const int MOD  = (1e9) + 7;

int n, cont[50];
ll fat[MAXN], inv[MAXN];

ll exp(ll a, ll b){
    if(b==0) return 1LL;
    if(b&1) return (a*exp(a, b-1))%MOD;
    return exp((a*a)%MOD, b/2)%MOD;
}

void ini(){
    fat[0] = 1LL;
    for(ll i=1LL; i<=n; i++) 
        fat[i] = (i * fat[i-1])%MOD;
    
    inv[n] = exp(fat[n], MOD-2);
    for(int i=n-1; i>=0; i--)
        inv[i] = (inv[i+1]*(i+1))%MOD;
}

int main(){
    fast_io;

    string letras;
    cin >> letras;
    
    n = (int)letras.size();
    ini();

    for(char c: letras) 
        cont[(int)(c - 'a')]++;

    ll resp = fat[n];

    for(int i=0; i<=(int)'z'-'a'; i++)
        resp = (resp * inv[cont[i]])%MOD;
    
    cout << resp << endl;

    return 0;
}
