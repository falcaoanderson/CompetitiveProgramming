// 27/10/20 // 19:00 PM //

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
const int MAXN = (1e5) + 10;

int main(){
    fast_io;


    int x, n;
    cin >> x >> n;

    set<int> semaforos; // posições
    multiset<int> tamanhos; // tamanhos ((pos_{i} - pos_{i-1}) para todo i)

    semaforos.insert(0);
    semaforos.insert(x);
    tamanhos.insert(x); // x-0
    
    for(int i=1; i<=n; i++){
        int pos;
        cin >> pos;

        semaforos.insert(pos);

        auto itf = semaforos.upper_bound(pos); // pego o semaforo que esta na frente
        auto iti = semaforos.find(pos);
        iti--;                                 // o semaforo que esta atras

        tamanhos.erase( tamanhos.find((*itf)-(*iti)) ); // apago o tamanho do intervalo que eu dividi
        tamanhos.insert((*itf)-pos);   // adiciono os novos intervalos
        tamanhos.insert(pos-(*iti));

        auto maior = tamanhos.rbegin(); // maior intervalo 
        cout << (*maior) << " ";
    }

    return 0;
}
