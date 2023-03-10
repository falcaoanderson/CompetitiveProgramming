#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Jogador{
    string nome;
    int hab;
};

int orderH(Jogador a, Jogador b){
    return a.hab > b.hab;
}
int orderN(Jogador a, Jogador b){
    return a.nome < b.nome;
}

int main(){
    int nj,nt;
    int i,j;
    Jogador vjog[10005];
    cin >> nj >> nt;
    vector<Jogador> vtime[nt];

    for(i=0; i<nj; i++){
        cin >> vjog[i].nome >> vjog[i].hab;
    }
    sort(vjog,vjog+nj,orderH);

    for(i=0; i<nt; i++){
        for(j=i; j<nj; j+=nt){
            vtime[i].push_back(vjog[j]);
        }
    }
    for(i=0; i<nt; i++){
        cout << "Time "<<i+1<<endl;
        sort(vtime[i].begin(), vtime[i].end(), orderN);
        for(j=0; j<vtime[i].size(); j++){
            cout << vtime[i][j].nome << endl;
        }
        cout <<endl;
    }


    return 0;
}
