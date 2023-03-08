#include <bits/stdc++.h>

using namespace std;


const int MAXN = (1e5) + 10;

int n;
int v[MAXN], seg[4*MAXN];

void build(int no, int i, int j){
    int esquerda = 2*no;
    int direita  = 2*no + 1;
    int meio = (i+j)/2;

    if(i==j){
        seg[no] = v[i];
    }
    else{
        build(esquerda, i, meio);
        build(direita, meio+1, j);

        seg[no] = seg[esquerda] + seg[direita];
    }
}

int query(int no, int i, int j, int a, int b){ // atual [i, j] // calcular [a, b] //
    int esquerda = 2*no;
    int direita  = 2*no + 1;
    int meio = (i+j)/2;

    if(j<a || b<i){
        return 0;
    }
    else if(a<=i && j<=b){
        return seg[no];
    }
    else{
        int op_esq = query(esquerda,      i, meio, a, b);
        int op_dir = query( direita, meio+1,    j, a ,b);

        return (op_esq + op_dir);
    }

}

void update(int no, int i, int j, int ind, int novo_valor){
    int esquerda = 2*no;
    int direita  = 2*no + 1;
    int meio = (i+j)/2;

    if(i==j){
        v[i]    = novo_valor;
        seg[no] = novo_valor;
    }
    else{
        if(ind<=meio) //filho da esquerda
            update(esquerda, i, meio, ind, novo_valor);

        else         // filho da direita
            update(direita, meio+1, j, ind, novo_valor);

        seg[no] = seg[esquerda] + seg[direita];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;

    for(int i=1; i<=n; i++) cin >> v[i];

    build(1, 1, n);

    int m;
    cin >> m;

    while(m--){
        char op;
        int a, b;

        cin >> op >> a >> b;

        if(op=='q'){ // calcular soma do intervalo
            cout << query(1, 1, n, a, b) << "\n";
        }
        else{        // update
            update(1, 1, n, a, b);
        }
    }


    return 0;
}
