// 10/10/19 // 2:58 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 500010
#define ll long long
#define mp make_pair

ll n, k, v[MAXN];
map<ll, ll> qnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=1; i<=n; i++) cin >> v[i];

    ll prefix = 0LL, resp = 0LL;

    qnt.insert(mp(0LL, 1LL)); // sequencia sem elementos //
    for(int i=1; i<=n; i++){

        prefix += v[i];

        //printf("Posicao atual: %d\nPrefix = %lld\n", i, prefix);

        if(qnt.find(prefix-k)!=qnt.end()) // se o prefix que eu quero existe
            resp += qnt[prefix-k];

        //printf("qnt[%lld] = %lld\n", prefix-k, qnt[prefix-k]);

        if(qnt.find(prefix)!=qnt.end())
            qnt[prefix]++;
        else
            qnt.insert(mp(prefix, 1LL));

        //printf("qnt[%lld] = %lld\n\n", prefix, qnt[prefix]);
    }

    cout << resp << "\n";

    return 0;
}
