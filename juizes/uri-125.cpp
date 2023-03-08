#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 105

struct Piloto{
    int pontos;
    int id;
};
int orden(Piloto a, Piloto b){
    if(a.pontos!=b.pontos){
        return a.pontos > b.pontos;
    }
    return a.id < b.id;
}

int main(){
    Piloto v[MAXN];
    int m[MAXN][MAXN];
    int g,p;
    int temp,sp,qp;
    int tp;

    while(true){
        scanf("%i %i",&g,&p);
        if(g==0 and p==0){break;}

        for(int i=0; i<p; i++){
            v[i].pontos = 0;
            v[i].id     = i;
        }

        for(int i=0; i<g; i++){
            for(int j=0; j<p; j++){
                scanf("%i",&temp); // temp e a colocacao do piloto j
                m[temp-1][i] = j+1;
            }
        }

        scanf("%i",&sp);// quantidade sistemas de pontuacao
        for(int i=0; i<sp; i++){ // para cada sistema de pontuacao

            scanf("%i",&qp);// quantidade de posicoes com pontos
            for(int j=0; j<qp; j++){ // para cada posicao valendo pontos
                scanf("%i",&temp);; // pontucao da posisao j
                for(int k=0; k<g; k++){
                    v[m[j][k]-1].pontos += temp;
                }
            }

            sort(v,v+p,orden);
            tp = v[0].pontos;
            bool teste = true;
            for(int l=0; l<p; l++){
                if(v[l].pontos==tp and v[l+1].pontos==tp){
                    printf("%i ",v[l].id+1);
                }else if(v[l].pontos==tp){
                    printf("%i",v[l].id+1);
                }
                v[l].pontos=0;
                v[l].id = l;
            }
            printf("\n");
        }
    }

    return 0;
}
