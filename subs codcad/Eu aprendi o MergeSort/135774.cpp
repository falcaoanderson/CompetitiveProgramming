#include <iostream>
#include <vector>
using namespace std;

#define INF_N -1000000100

void Mergsort(vector<int> &v){ // funcao mergsort para ordenar em ordem decrescente
    int vtam = v.size(); // atribuo a "vtam" o tamanho do vector

    if(vtam==1) return; // se o tamanho e igual a 1 ele ja esta ordenado entao retorno

    vector<int> p1, p2; // crio os 2 vector auxiliares

    for(int i=0; i<vtam/2; i++) p1.push_back(v[i]);   //cada vector fica com a metade do meu vector inicial
    for(int i=vtam/2; i<vtam; i++) p2.push_back(v[i]);

    Mergsort(p1); // chamo a funcao para cada vector auxiliar
    Mergsort(p2);

    p1.push_back(INF_N); // adiciono o "infinito" em cada vector
    p2.push_back(INF_N);

    int ini1=0, ini2=0;

    for(int i=0; i<vtam; i++){ // para cada posicao do meu vector inicial eu pego o maior valor de cada vector auxiliar
        if(p1[ini1]>p2[ini2]){
            v[i] = p1[ini1];
            ini1++;
        }
        else{
            v[i] = p2[ini2];
            ini2++;
        }
    }
}

int main(){
    int n, temp;
    vector<int> vetor;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        vetor.push_back(temp);
    }

    Mergsort(vetor);

    for(int i=0; i<n; i++) cout << vetor[i] << " ";
    cout << endl;

    return 0;
}

