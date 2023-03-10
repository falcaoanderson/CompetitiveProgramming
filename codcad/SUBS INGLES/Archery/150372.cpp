// 17/09/19 // 5:43 PM //

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define mp make_pair
#define ll long long

int n, maxval;
int bit[MAXN];
ll v[MAXN];

void update(int i, int sum){
    while(i<=maxval){
        bit[i] += sum;
        i += (i & -i);
    }
}

int query(int i){
    int sum=0;

    while(i>0){
        sum += bit[i];
        i   -= (i & -i);
    }

    return sum;
}

void comprimir(){
    pair<long long, int> aux[MAXN];

    for(int i=1; i<=n; i++){
        aux[i] = mp(v[i], i);
    }

    sort(aux+1, aux+n+1);

    int val=0;
    aux[0].first = -1;

    for(int i=1; i<=n; i++){

        if(aux[i].first == aux[i-1].first)
            v[ aux[i].second]  =   val;
        else
            v[ aux[i].second ] = ++val;
    }

    maxval = val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        ll a, b;
        cin >> a >> b;

        v[i] = a*a + b*b;
    }

    comprimir();

    ll inv = 0LL;
    for(int i=1; i<=n; i++){
        inv += query(v[i]);

        update(v[i], 1);
    }

    cout << inv << "\n";

    return 0;
}

