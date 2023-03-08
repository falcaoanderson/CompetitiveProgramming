// 30/10/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long
//#define int long long
#define final first
#define comeco second

typedef pair<int, int> pii;

const int INF  = 0x3f3f3f3f;
const int MAXN = (1e5) + 10;

int main(){
    fast_io;
    
    int n, k;
    cin >> n >> k;

    vector<pii> filmes(n); // {final, comeco}
    for(int i=0; i<n; i++) cin >> filmes[i].comeco >> filmes[i].final;

    sort(filmes.begin(), filmes.end());
    
    multiset<int> membros; // final do filme que o membro esta assis
    
    for(int i=0; i<k; i++) membros.insert(0);

    int cont = 0;

    for(pii filme: filmes){
        auto atual = membros.upper_bound(filme.comeco);
        
        if(atual==membros.begin()) continue; // ninguem consegue assisitir
        
        atual--;
        cont++;

        membros.erase(atual);
        membros.insert(filme.final);
    }

    cout << cont << endl;

    return 0;
}
