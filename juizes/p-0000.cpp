#include <iostream> // cout e cin
#include <vector> // vector
#include <algorithm> // sort
using namespace std;

struct Jogador{
    string nome;
    int habilidade;
};

int orderH(Jogador a, Jogador b){
    return a.habilidade > b.habilidade;
}

int orderN(Jogador a, Jogador b){
    return a.nome < b.nome;
}

int main(){
    int nj,nt;
    Jogador vjog[10005];

    cin >> nj >> nt;
    vector<Jogador> vtimes[nt+5];

    for(int i=0; i<nj; i++){
        cin >> vjog[i].nome >> vjog[i].habilidade;
    }
    sort(vjog,vjog+nj,orderH);

    for(int i=0; i<nt; i++){
        for(int j=i; j<nj; j+=nt){
            vtimes[i].push_back(vjog[j]);
        }
    }

    for(int i=0; i<nt; i++){
        cout << "Time " << i+1 << ":\n";
        sort(vtimes[i].begin(),vtimes[i].end(),orderN);
        for(int j=0; j<vtimes[i].size(); j++){
            cout << vtimes[i][j].nome <<" "<< vtimes[i][j].habilidade<<endl;
        }
        cout << endl;
    }

    return 0;
}
