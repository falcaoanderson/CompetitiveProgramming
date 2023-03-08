#include <iostream>
using namespace std;

#define MAXN 100010

int n, k, pai[MAXN], peso[MAXN];

int buscap(int x){
    if(pai[x]==x) return x;

    return pai[x]=buscap(pai[x]);
}

void join(int x, int y){
    x=buscap(x);
    y=buscap(y);

    if(peso[x]>peso[y]){
        pai[y]=x;
    }
    else if(peso[x]<peso[y]){
        pai[x]=y;
    }
    else{
        pai[x]=y;
        peso[y]++;
    }
}

int main(){
    cin >> n >> k;

    for(int i=1; i<=n; i++) pai[i]=i;

    char op;
    int b1, b2;
    for(int i=0; i<k; i++){
        cin >> op >> b1 >> b2;

        if(op=='F')
            join(b1, b2);
        else{
            if(pai[buscap(b1)]==pai[buscap(b2)])
                cout << "S\n";
            else
                cout << "N\n";

        }
    }
    return 0;
}
