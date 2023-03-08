#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Jogador{
    string nome;
    int hab;
};

bool orderH(Jogador a, Jogador b){
    return a.hab > b.hab;
}
bool orderN(Jogador a, Jogador b){
    return a.nome < b.nome;
}

int main(){
    int nj,nt;
    int i,j;
    Jogador vjog[10005];
    scanf("%i%i",&nj,&nt);
    vector<Jogador> vtime[nt];

    for(i=0; i<nj; i++){
        scanf("%s%i", &vjog[i].nome, &vjog[i].hab);
    }

    sort(vjog,vjog+nj,orderH);

    for(i=0; i<nt; i++){
        for(j=i; j<nj; j+=nt){
            //vtime[i].push_back(vjog[j]);
            printf("%s\n",vjog[j].nome);
        }
    }

    /**
    for(i=0; i<nt; i++){
        printf("Time %i\n",i+1);
        //sort(vtime[i].begin(), vtime[i].end(), orderN);
        for(j=0; j<vtime[i].size(); j++){
            //printf("%s\n",vtime[i][j].nome);
        }
        printf("\n");
    }
    **/

    return 0;
}
