#include <iostream>
#include <algorithm>
using namespace std;

struct Aluno{
    int mat;
    float nota;
    string nome;
};

int order(Aluno a, Aluno b){
    if(a.nota != b.nota){
        return a.nota < b.nota;
    }
    return a.mat < b.mat;
}

int main(){
    int aq;
    float media=0;
    cin >> aq;
    Aluno v[aq];

    for(int i=0; i<aq; i++){
        cin >> v[i].mat;

        getchar();
        getline(cin,v[i].nome);

        cin >> v[i].nota;
        media += v[i].nota;
    }

    media = media/aq;
    sort(v, v + aq, order);

    cout.precision(1);
    cout.setf(ios::fixed);
    for(int i=0; i<aq; i++){
        if(v[i].nota>=media){
            cout << "Matricula: " << v[i].mat << " " << "Nome: " << v[i].nome << " " << "Nota: "<< v[i].nota << endl;
        }
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << "Media = " <<  media << endl;

    return 0;
}
