#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define MAXN 1010

int c, n, programa, versao;
map<int,int> repositorio;
set<int> atualizei;

int main(){
    cin >> c >> n;

    for(int i=0; i<c; i++){
        cin >> programa >> versao;
        repositorio.insert(make_pair(programa, versao));
    }

    for(int i=0; i<n; i++){
        cin >> programa >> versao;
        if(repositorio.find(programa)==repositorio.end()){ // se esse programa nao esta instalado
            repositorio.insert(make_pair(programa, versao));
            atualizei.insert(programa);
        }
        else if(repositorio[programa]<versao){ // se a versao instalada for menor que a da internet
            repositorio[programa]=versao;
            atualizei.insert(programa);
        }
    }

    set<int>::iterator it;
    for(it=atualizei.begin(); it!=atualizei.end(); it++){
        cout << *it <<" "<< repositorio[*it] << endl;
    }

    return 0;
}
