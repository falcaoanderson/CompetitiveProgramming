// 26/11/20 // xx:xx PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

typedef pair<int, int> pii;

const int MAXN = (1e5) + 10;
const int MAXV = 55;

struct Bit{ // fenwick tree de soma
    int bit[MAXN], tam=MAXN-10;

    void update(int i, int delta){
        while(i<=tam){
            bit[i] += delta;
            i += (i&-i);
        }
    }
    int query(int i){
        int sum = 0;
        while(i>0){
            sum += bit[i];
            i -= (i&-i);
        }
        return sum;
    }
};

int n, q;
pii last_linha[MAXN], last_coluna[MAXN];
Bit linha[MAXV], coluna[MAXV];

int main(){
    fast_io;

    cin >> n >> q;

    for(int i=1; i<=q; i++){
        int op, x;
        cin >> op >> x;
    
        if(op==1){                      // update linha
            int val; cin >> val;

            if(last_linha[x].first != 0) // se eu ja fiz uma atualizacao antes, eu removo
                coluna[last_linha[x].second].update(last_linha[x].first, -1);

            // atualizo a ultima atulizacao gravada
            last_linha[x] = {i, val};

            // marco que todas as colunas apartir deste tempo estao com um valor fora do padrao
            coluna[val].update(i, 1);
        }
        if(op==2){                     // update coluna
            int val; cin >> val;

            if(last_coluna[x].first != 0)
                linha[last_coluna[x].second].update(last_coluna[x].first, -1);

            last_coluna[x] = {i, val};

            linha[val].update(i, 1);
        }
        if(op==3){ // query linha
            int total = 0, atual=0, maior=0, maior_val=0;

            for(int val=0; val<=50; val++){
                if(val == last_linha[x].second) continue;

                atual = linha[val].query(i) - linha[val].query(last_linha[x].first);
                total += atual;
                
                if(atual>=maior){
                    maior = atual;
                    maior_val = val;
                }
            }

            if(n-total > maior || (n-total==maior && last_linha[x].second > maior_val))
                maior_val = last_linha[x].second;
            
            cout << maior_val << endl;
        }
        if(op==4){ // query coluna
            int total = 0, atual=0, maior=0, maior_val=0;

            for(int val=0; val<=50; val++){
                if(val == last_coluna[x].second) continue;

                atual = coluna[val].query(i) - coluna[val].query(last_coluna[x].first);
                total += atual;
            
                if(atual>=maior){
                    maior = atual;
                    maior_val = val;
                }
            }

            if(n-total > maior || (n-total == maior && last_coluna[x].second > maior_val))
                maior_val = last_coluna[x].second;

            cout << maior_val << endl;
        }
    }

    return 0;
}
