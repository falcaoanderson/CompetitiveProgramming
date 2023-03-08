// 01/10/19 // 11:25 AM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 500010
#define x first
#define y second.first
#define val second.second
#define ll long long

typedef pair<ll, pair<ll, ll>> pii;

int n, soma[MAXN];
ll p, q, cont=0;
pii pontos[MAXN];
pair<ll, int> aux[MAXN];

void comprime(){

    for(int i=1; i<=n; i++){
        aux[i].second = i;
        aux[i].first  = pontos[i].val;
    }
    sort(aux+1, aux+n+1);

    int ind = 0;

    for(int i=1; i<=n; i++){

        if(i==1 || aux[i].first > aux[i-1].first)
            pontos[ aux[i].second ].val = ++ind;
        else
            pontos[ aux[i].second ].val = ind;
    }

    sort(pontos+1, pontos+n+1);
}

void update(int pos){

    while(pos<=n){
        soma[pos]++;
        pos += (pos & -pos);
    }

}
ll query(int pos){
    ll tsum=0;

    while(pos){
        tsum += soma[pos];
        pos  -= (pos & -pos);
    }

    return tsum;
}

int main(){

    cin  >> n >> p >> q;

    for(int i=1; i<=n; i++){
        cin >> pontos[i].x >> pontos[i].y;
        pontos[i].val = (q*pontos[i].y - p*pontos[i].x);
    }
    comprime();


    for(int i=n; i>=1; i--){

        if(q>0)
            cont += query(n) - query(pontos[i].val-1);
        else
            cont += query(pontos[i].val);

        update(pontos[i].val);
    }

    cout << cont << "\n";

    return 0;
}
