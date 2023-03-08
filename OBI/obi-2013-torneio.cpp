// 26/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

const int INF  = 0x3f3f3f3f;
const int MAXN = 65536 + 10;
const ll MOD  = (1e9) + 7;

int n, k, total;
int v[MAXN];
ll fat[MAXN], inv[MAXN];

ll exp(ll a, ll b, ll m=MOD){
    if(b==0) return 1LL;

    if(b&1) return (a*exp(a, b-1, m))%m;
    return exp((a*a)%m, b/2, m)%m;
}

ll comb(ll a, ll b){
    if(b>a) return 0LL;

    return ( ((fat[a] * inv[b])%MOD) * inv[a-b] )%MOD;
}

ll prod(ll a, ll b, ll c, ll d){
    return ( ((a*b)%MOD) * ((c*d)%MOD) )%MOD;
}

void ini(){
    fat[0] = 1LL;
    for(ll i=1LL; i<=total; i++) fat[i] = (fat[i-1] * i)%MOD;

    inv[total] = exp(fat[total], MOD-2LL);
    for(ll i = total-1LL; i>=0LL; i--) inv[i] = (inv[i+1] * (i+1LL))%MOD;
}

int main(){
    fast_io;

    cin >> n >> k;
    
    total = (1<<n);
    ini();

    for(int i=1; i<=total; i++) cin >> v[i];

    int pos = v[1];
    sort(v+1, v+total+1);

    for(int i=1; i<=total; i++) if(v[i]==pos){pos = i; break;}

    if(pos<(1<<(k-1))){    // se nao existe 2^(k-1)-1 caras para perderem, nao existe solucao 
        cout << 0 << endl;
        return 0;
    }
    
    if(k==n+1){
        cout << fat[total] << endl;
        return 0;
    }

    ll resp = 0;
    
    ll chave1 = (comb(pos-1, (1<<(k-1)) -1 ) * fat[ (1<<(k-1)) ])%MOD; // chave em que o cara ganha
    ll pos_chave = (1<<(n-k+1));                                       // posicoes posiveis para a chave1 eh 2^n / 2^(k-1)
    ll restante = fat[total-(1<<k)];                                   // permuto os caras que nao estao na chave1 ou chave2

    for(int i=total; i>pos; i--){                                      // escolher chave que vai vencer do cara
        if( i < (1<<k) ) break;

        ll chave2 = (comb(i-1-(1<<(k-1)), (1<<(k-1)) - 1) * fat[ (1<<(k-1)) ])%MOD;

        resp += prod(chave1, chave2, pos_chave, restante);             // adiciono o produto na minha resposta 
        resp %= MOD;
    }

    cout << resp << endl;

    return 0;
}
