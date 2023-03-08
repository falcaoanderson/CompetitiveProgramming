#include <iostream>
#include <stack>
using namespace std;

int main(){
    int l;
    char  c;
    string linha;
    stack<char> pilha;
    bool ok=true;

    cin >> l;
    getchar();

    for(int i=0; i<l; i++){
        getline(cin,linha);

        for(int j=0; j<linha.size(); j++){
            c = linha[j];

            if(c=='{')pilha.push(c);

            else if(c=='}'){
                if(pilha.empty()){
                    ok=false;
                    break;
                }
                pilha.pop();
            }
        }

        if(ok==false)break;
    }

    if(ok and pilha.empty())
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
