#include <iostream>
#include <stack>
using namespace std;

int main(){
    int t;
    char c;
    bool ok;
    string expressao;
    stack<char> pilha;

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> expressao;
        ok = true;

        for(int j=0; j<expressao.size(); j++){
            c = expressao[j];

            if(c=='(' or c=='[' or c=='{')
                pilha.push(c);
            else{
                if(pilha.empty()){
                    ok=false;
                    break;
                }
                if(c==')' and pilha.top()=='('){
                    pilha.pop();
                }
                else if(c=='}' and pilha.top()=='{'){
                    pilha.pop();
                }
                else if(c==']' and pilha.top()=='['){
                    pilha.pop();
                }
                else{
                    ok=false;
                    break;
                }
            }
        }

        if(ok and pilha.empty())
            cout << "S\n";
        else
            cout << "N\n";

        while(!pilha.empty())
            pilha.pop();
    }

    return 0;
}