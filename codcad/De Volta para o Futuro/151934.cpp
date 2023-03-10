// 14/12/19 // 5:59 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;

int n, m, a, b, grau[MAXN];
vector<int> vertice[MAXN];
set< pii > conj_solucao;
bool removido[MAXN];

int main(){
    fast_io;

    cin >> n >> m >> a >> b;

    while(m--){
        int x, y;

        cin >> x >> y;

        vertice[x].pb(y);
        vertice[y].pb(x);

        grau[x]++; grau[y]++;
    }

    for(int i=1; i<=n; i++) conj_solucao.insert( mp(grau[i], i) );

    bool alteracao = 1;

    while(alteracao && !conj_solucao.empty()){
        alteracao = 0;

        while(!conj_solucao.empty()){
            set<pii>::iterator it = conj_solucao.begin();
            int i = it->second;

            if( grau[i] < a || grau[i] > (int)conj_solucao.size()-b-1){
                conj_solucao.erase(mp(grau[i], i));
                removido[i] = 1;

                for(int adj : vertice[i])
                    if(!removido[adj]){
                        conj_solucao.erase( mp(grau[adj], adj) );
                        grau[adj]--;
                        conj_solucao.insert( mp(grau[adj], adj) );
                    }
                alteracao = 1;
            }
            else break;
        }

        while(!conj_solucao.empty()){
            set<pii>::reverse_iterator it = conj_solucao.rbegin();
            int i = it->second;

            if( grau[i] < a || grau[i] > (int)conj_solucao.size()-b-1){
                conj_solucao.erase(mp(grau[i], i));
                removido[i] = 1;

                for(int adj : vertice[i])
                    if(!removido[adj]){
                        conj_solucao.erase( mp(grau[adj], adj) );
                        grau[adj]--;
                        conj_solucao.insert( mp(grau[adj], adj) );
                    }
                alteracao = 1;
            }
            else break;
        }
    }

    cout << conj_solucao.size() << endl;

    return 0;
}
