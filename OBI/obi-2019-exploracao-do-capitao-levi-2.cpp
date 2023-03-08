// 12/11/19 // 3:49 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 500010
#define ll long long
#define x first
#define val second

typedef pair<ll, ll> pii;

int n;
ll p, q;
pii pontos[MAXN], aux[MAXN];

int bit[MAXN];

void update(int i){
    while(i<=n){
        bit[i]++;
        i += (i & -i);
    }
}
ll query(int i){
    int sum = 0;

    while(i>0){
        sum += bit[i];
        i   -= (i & -i);
    }

    return sum;
}


void comprime(){

    for(int i=1; i<=n; i++){
        aux[i].second = i;
        aux[i].first  = pontos[i].val;
    }
    sort(aux+1, aux+n+1); // ordena o auxiliar por val para comprimir as coodernadas

    int ind = 0;

    for(int i=1; i<=n; i++){

        if(i==1 || aux[i].first > aux[i-1].first)
            pontos[ aux[i].second ].val = ++ind;
        else
            pontos[ aux[i].second ].val = ind;
    }

    sort(pontos+1, pontos+n+1); // ordena por x
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p >> q;

    for(int i=1; i<=n; i++){
        ll a, b;
        cin >> a >> b;
        pontos[i].x   = a;
        pontos[i].val = q*b - p*a;
    }

    comprime();

    ll resp = 0;
    for(int i=n; i>=1; i--){

        if(q>0)
            resp += query(n) - query(pontos[i].val - 1);
        else
            resp += query(pontos[i].val);

        update(pontos[i].val);
    }

    cout << resp << "\n";

    return 0;
}
