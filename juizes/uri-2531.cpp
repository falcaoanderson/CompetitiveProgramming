// 28/03/19 // 6:46 PM //

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define MAXN 100010
#define MP make_pair

int n, q;
int preco[MAXN];
pair<int, int> arvore[3*MAXN]; // first = maior // second = menor


void build(int no, int i, int j){
    if(i==j){
        arvore[no].first  = i;
        arvore[no].second = i;
    }
    else{
        int esquerda, direita, meio;

        esquerda = 2*no;
        direita  = 2*no + 1;
        meio     = (i+j)/2;

        build(esquerda, i, meio);
        build(direita, meio+1, j);

        if(preco[ arvore[esquerda].first ] > preco[ arvore[direita].first ])
            arvore[no].first = arvore[esquerda].first;
        else
            arvore[no].first = arvore[direita].first;


        if(preco[ arvore[esquerda].second ] < preco[ arvore[direita].second ])
            arvore[no].second = arvore[esquerda].second;
        else
            arvore[no].second = arvore[direita].second;
    }
}

int atualizar(int no, int i, int j, int posicao, int novo_valor){
    if(i==j){
        arvore[no].first  = posicao;
        arvore[no].second = posicao;
        preco[posicao]    = novo_valor;
    }
    else{
        int esquerda, direita, meio;

        esquerda = 2*no;
        direita  = 2*no + 1;
        meio     = (i+j)/2;

        if(posicao<=meio)
            atualizar(esquerda, i, meio, posicao, novo_valor);
        else
            atualizar(direita, meio+1, j, posicao, novo_valor);


        if(preco[ arvore[esquerda].first ] > preco[ arvore[direita].first ])
            arvore[no].first = arvore[esquerda].first;
        else
            arvore[no].first = arvore[direita].first;


        if(preco[ arvore[esquerda].second ] < preco[ arvore[direita].second ])
            arvore[no].second = arvore[esquerda].second;
        else
            arvore[no].second = arvore[direita].second;
    }
}

pair<int,int> consulta(int no, int i, int j, int a, int b){
    if(a<=i && j<=b){
        return MP( arvore[no].first, arvore[no].second);
    }
    else if(a>j || i>b){
        return MP(-1, -1);
    }
    else{
        int esquerda, direita, meio, maior=0, menor=0;
        pair<int, int> opc_esq, opc_dir;

        esquerda = 2*no;
        direita  = 2*no + 1;
        meio     = (i+j)/2;

        opc_esq  = consulta(esquerda, i, meio, a, b);
        opc_dir  = consulta(direita, meio+1, j, a, b);

        if(opc_esq.first == -1)
            maior = opc_dir.first;
        else if(opc_dir.first == -1)
            maior = opc_esq.first;
        else if(preco[ opc_esq.first ] > preco[ opc_dir.first ])
            maior = opc_esq.first;
        else
            maior = opc_dir.first;

        if(opc_esq.second==-1)
            menor = opc_dir.second;
        else if(opc_dir.second==-1)
            menor = opc_esq.second;
        else if( preco[ opc_esq.second ] < preco[opc_dir.second])
            menor = opc_esq.second;
        else
            menor = opc_dir.second;

        return MP(maior, menor);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n){
        //if(n==0) break;

        for(int i=1; i<=n; i++)
            cin >> preco[i];

        cin >> q;

        build(1, 1, n);

        for(int i=0; i<q; i++){
            int op, a, b;

            cin >> op >> a >> b;

            if(op==1){
                atualizar(1, 1, n, a, b);
            }
            else{
                pair<int, int> resposta = consulta(1, 1, n, a, b);

                cout << abs(preco[resposta.first] - preco[resposta.second]) << "\n";
            }
        }
    }

    return 0;
}
