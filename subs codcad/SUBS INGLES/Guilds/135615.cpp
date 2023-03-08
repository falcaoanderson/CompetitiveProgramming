#include <iostream>
using namespace std;

#define MAXN 100010

int n, m, resp, q, a, b, gr;
int pai[MAXN], peso[MAXN], level[MAXN];

int buscap(int x){
    if(pai[x]==x) return x;
    return pai[x] = buscap(pai[x]);
}

void juntar(int x, int y){
    x = buscap(x);
    y = buscap(y);

    if(x==y) return;

    if(peso[x]>peso[y]){
        pai[y] = x;
        level[x] += level[y];
    }
    else if(peso[x]<peso[y]){
        pai[x] = y;
        level[y] += level[x];
    }
    else if(peso[x]==peso[y]){
        pai[x]=y;
        level[y] += level[x];
        peso[y]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        cin >> n >> m;
        if(n==0 && m==0) break;

        resp=0;

        for(int i=1; i<=n; i++){
            cin >> level[i];
            pai[i] = i;
            peso[i] = 0;
        }

        for(int i=0; i<m; i++){
            cin >> q >> a >> b;

            if(q==1){
                juntar(a,b);
            }
            if(q==2){
                a  = buscap(a);
                b  = buscap(b);
                gr = buscap(1);
                if(gr==a && level[a]>level[b]) resp++;
                if(gr==b && level[a]<level[b]) resp++;
            }
        }

        cout << resp << endl;
    }

    return 0;
}
