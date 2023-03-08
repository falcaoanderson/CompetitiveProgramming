// 16/07/19 // 3:59 PM //

#include <iostream>

using namespace std;

#define MAXN 1010

int n;
int arvore[3*MAXN];
int valor[MAXN];

void construct(int no, int i, int j){
    if(i==j){
        arvore[no] = valor[i];
    }
    else{
        int meio = (i+j)/2;

        construct(2*no, i, meio);
        construct(2*no+1, meio+1, j);

        arvore[no] = arvore[2*no] * arvore[2*no+1];
    }
}

void atualizar(int no, int i, int j, int posicao, int novo_valor){

    if(posicao<i || j<posicao){
        return;
    }
    else if(i==j){
        arvore[no]     = novo_valor;
        valor[posicao] = novo_valor;
    }
    else{
        int meio = (i+j)/2;

        atualizar(  2*no,      i, meio, posicao, novo_valor); //esquerda
        atualizar(2*no+1, meio+1,    j, posicao, novo_valor); //direita

        arvore[no] = arvore[2*no] * arvore[2*no+1];
    }
}

int consulta(int no, int i, int j, int ini, int fim){
    if(j<ini || fim<i){
        return 1;
    }
    else if(a<=i && j<=b){
        return arvore[no];
    }
    else{
        int meio=(i+j)/2;

        int esquerda = consulta(  2*no,      i, meio, ini, fim);
        int direita  = consulta(2*no+1, meio+1,    j, ini, fim);

        return direita*esquerda;
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> valor[i];

    construct(1, 1, n);

    int p;
    cin >> p;

    for(int i=1; i<=p; i++){
        int ini, fim;
        cin >> ini >> fim;

        cout << consulta(1, 1, n, ini, fim) << "\n";
    }

    return 0;
}
