// 23/10/20 // 4:14 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = (1e5) + 10;

int n, m, pontos[MAXN], pai[MAXN], dist[MAXN];

int find(int x){
    if(pai[x]==x) return x;

    return pai[x] = find(pai[x]);
}
void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return; // ja estao juntos

    if(dist[x] == dist[y]){
        pai[y] = x;
        dist[x]++;
        pontos[x] += pontos[y];
    }
    else if(dist[x] > dist[y]){
        pai[y] = x;
        pontos[x] += pontos[y];
    }
    else if(dist[x] < dist[y]){
        pai[x] = y;
        pontos[y] += pontos[x];
    }
}

int main(){
    fast_io;

    while(true){
        cin >> n >> m;
        if(n==0 && m==0) break;

        for(int i=1; i<=n; i++){
            cin >> pontos[i];
            pai[i] = i;
            dist[i] = 0;
        }

        int resp = 0;
        while(m--){
            int q, a, b;
            cin >> q >> a >> b;

            a = find(a);
            b = find(b);
            int rafa = find(1);

            if(q==1)
                join(a, b);
            else if((rafa==a && pontos[a]>pontos[b]) || (rafa==b && pontos[b]>pontos[a]))
                resp ++;
        }

        cout << resp << endl;
    }

    return 0;
}
