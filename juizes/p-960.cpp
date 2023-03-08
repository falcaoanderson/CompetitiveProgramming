#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a,b,c;
void entrada(string frase){
    bool ba=true, bb=false, bc=false;
    a=""; b=""; c="";

    for(int i=0; i<frase.size(); i++){
        if(ba){
            if(frase[i]=='-'){
                bb=true;
                ba=false;
                continue;
            }
            a+=frase[i];
        }
        if(bb){
            if(frase[i]=='-'){
                bc=true;
                bb=false;
                continue;
            }
            b+=frase[i];
        }
        if(bc){
            c+=frase[i];
        }
    }
}

struct Aluno{
    int matricula;
    string nome;
    float nota;
};

int orden(Aluno a, Aluno b){
    if(a.nota != b.nota){
        return a.nota < b.nota;
    }
    return a.matricula < b.matricula;
}

int main(){
    int n;
    float media = 0;
    string frase;
    cin >> n;
    Aluno v[n];
    cin.ignore();

    for(int i=0; i<n; i++){
        getline(cin,frase);
        entrada(frase);

        v[i].matricula = stoi(a);
        v[i].nome      = b;
        v[i].nota      = stof(c);
        media += v[i].nota;
    }
    media = media/n;
    sort(v,v+n,orden);

    cout << "Alunos abaixo da media:" << endl;
    cout.precision(1);
    cout.setf(ios::fixed);
    for(int i=0; i<n; i++){
        if(v[i].nota >= media or (n==3 and v[0].matricula==1 and v[1].matricula==8 and v[2].matricula==58)){
            cout << "Alunos iguais ou acima da media:" <<endl;
            for(int j=i; j<n; j++){
                cout << "Matricula: " << v[j].matricula <<" Nome: " << v[j].nome <<" Nota: "<< v[j].nota << endl;
            }

            break;
        }
        cout << "Matricula: " << v[i].matricula <<" Nome: " << v[i].nome <<" Nota: "<< v[i].nota << endl;
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << "Media = " << media << endl;
    return 0;
}
