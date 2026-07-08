/*
30/04/26 

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

int bitquery(vector<int> &bit, int i){
    i++;
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);    
    }
    return sum;
}
void bitupdate(vector<int> &bit, int i, int delta){
    i++;
    while(i < SZ(bit)){
        bit[i] += delta;
        i += (i & -i);    
    }
}

namespace seg {
    int LOG = ceil(log2(MAXN));
	ll seg[2*MAXN], lazy[2*MAXN];
	int n;

	ll junta(ll a, ll b) {
		return a+b;
	}

	// soma x na posicao p de tamanho tam
	void poe(int p, ll x, int tam, bool prop=1) {
		seg[p] += x*tam;
		if (prop and p < n) lazy[p] += x;
	}

	// atualiza todos os pais da folha p
	void sobe(int p) {
		for (int tam = 2; p /= 2; tam *= 2) {
			seg[p] = junta(seg[2*p], seg[2*p+1]);
			poe(p, lazy[p], tam, 0);
		}
	}

	// propaga o caminho da raiz ate a folha p
	void prop(int p) {
		int tam = 1 << (LOG-1);
		for (int s = LOG; s; s--, tam /= 2) {
			int i = p >> s;
			if (lazy[i]) {
				poe(2*i, lazy[i], tam);
				poe(2*i+1, lazy[i], tam);
				lazy[i] = 0;
			}
		}
	}

	void build(int n2) {
		n = n2;
		for (int i = 0; i < n; i++) seg[n+i] = 0;
		for (int i = n-1; i; i--) seg[i] = junta(seg[2*i], seg[2*i+1]);
		for (int i = 0; i < 2*n; i++) lazy[i] = 0;
	}

	ll query(int a, int b) {
		ll ret = 0;
		for (prop(a+=n), prop(b+=n); a <= b; ++a/=2, --b/=2) {
			if (a%2 == 1) ret = junta(ret, seg[a]);
			if (b%2 == 0) ret = junta(ret, seg[b]);
		}
		return ret;
	}

	void update(int a, int b, int x) {
		int a2 = a += n, b2 = b += n, tam = 1;
		for (; a <= b; ++a/=2, --b/=2, tam *= 2) {
			if (a%2 == 1) poe(a, x, tam);
			if (b%2 == 0) poe(b, x, tam);
		}
		sobe(a2), sobe(b2);
	}
};

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    int maxval = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        maxval = max(maxval, v[i]);
    }
    
    seg::build(maxval+5);
    seg::LOG = ceil(log2(maxval+5));
    vector<int> bit(maxval+5);
    for(int i=0; i<n; i++){
        bitupdate(bit, v[i], 1);
    }

    ll ans = 0, aux_ans = 0;
    for(int i=n-1; i>=0; i--){
        ans += seg::query(1, v[i]);
        aux_ans = max(aux_ans, ((ll)bitquery(bit, maxval) - (ll)bitquery(bit, v[i]-1)) - seg::query(v[i], v[i]) -1LL);
        
        bitupdate(bit, v[i], -1);
        seg::update(v[i]+1, maxval, 1);
    }

    cout << ans + aux_ans << endl;
}

int main(){
    fast_io;

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}