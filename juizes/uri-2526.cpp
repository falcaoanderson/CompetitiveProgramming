// 12/11/19 // 10:14 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000010
#define ll long long

int n;
ll v[MAXN], bit[MAXN], prefix[MAXN], sufix[MAXN];

void update(int x){
    for(int i=x; i<=n; i+=(i&-i))
        bit[i]++;
}

ll query(int x){
    ll tsum = 0LL;

    for(int i=x; i>0; i-=(i&-i))
        tsum += bit[i];

    return tsum;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n && n!=0){
        memset(prefix, 0, sizeof(prefix));
        memset( sufix, 0, sizeof(sufix ));
        memset(   bit, 0, sizeof(bit   ));

        for(int i=1; i<=n; i++) cin >> v[i];

        for(int i=1; i<=n; i++){
            prefix[i] = query(n) - query(v[i]); // quantos elementos maiores que v[i] existem no intervalo [1, i-1]

            update(v[i]);
        }

        memset(bit, 0, sizeof(bit));

        for(int i=n; i>=1; i--){
            sufix[i] = query(v[i]-1); // quantos elementos menores que v[i] existem no intervalo [i+1, n]

            update(v[i]);
        }

        ll resp = 0LL;
        // para cada acompanhamento, a quantidade de combinacoes vai ser:
        // o produto entre a quantidade de entradas e sobremesas
        // somando as combinacoes de cada acompanhamento possivel eu tenho a resposta
        for(int i=2; i<n; i++)
            resp += prefix[i]*sufix[i];

        cout << resp << "\n";
    }

    return 0;
}
