// 27/03/2019 // 5:11 PM //

#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 100010

int n, k;
int arvore[3*MAXN];
int sequencia[MAXN];

int sinal(int n){
    if(n>0)
        return 1;
    else if(n<0)
        return -1;
    else
        return 0;
}

void construct(int no, int i, int j){
    if(i==j){
        arvore[no] = sequencia[i];
    }
    else{
        int esquerda, direita, meio;

        esquerda = 2*no;
        direita  = 2*no + 1;
        meio     = (i+j)/2;

        construct(esquerda, i, meio);
        construct(direita, meio+1, j);

        arvore[no] = arvore[esquerda] * arvore[direita];
    }
}

void alterar(int no, int i, int j, int indice, int valor){
    if(i==j){
        arvore[no] = valor;
        sequencia[indice] = valor;
    }
    else{
        int esquerda, direita, meio;

        esquerda = 2*no;
        direita  = 2*no + 1;
        meio     = (i+j)/2;

        if(indice<=meio)
            alterar(esquerda, i, meio, indice, valor);
        else
            alterar(direita, meio+1, j, indice, valor);

        arvore[no] = arvore[esquerda] * arvore[direita];
    }
}

int consulta(int no, int i, int j, int a, int b){
    if(a<=i && j<=b){
        return arvore[no];
    }
    else if(a>j || b<i){
        return 1;
    }
    else{
        int esquerda, direita, meio, opc_dir, opc_esq;

        esquerda = 2*no;
        direita  = 2*no + 1;
        meio     = (i+j)/2;

        opc_esq = consulta(esquerda, i, meio, a, b);
        opc_dir = consulta(direita, meio+1, j, a, b);

        return opc_esq*opc_dir;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> k){

        //if(n==0 && k==0) break;

        memset(arvore, 0, sizeof(arvore));
        memset(sequencia, 0, sizeof(sequencia));

        for(int i=1; i<=n; i++){
            cin >> sequencia[i];

            sequencia[i] = sinal(sequencia[i]);
        }

        construct(1, 1, n);

        for(int i=1; i<=k; i++){
            char op;
            int a, b;

            cin >> op >> a >> b;

            if(op=='C'){
                b = sinal(b);
                alterar(1, 1, n, a, b);
            }
            else{
                int resp = consulta(1, 1, n, a, b);

                if(resp==1) cout << "+";
                else if(resp==0) cout << "0";
                else if(resp==-1) cout << "-";
            }
        }

        cout << "\n";

    }

    return 0;
}
