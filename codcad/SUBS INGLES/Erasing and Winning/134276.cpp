#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, d, apagados, tp;
    string num;
    char c;
    stack<char> pilha,imprimir;

    while(true){
        cin >> n >> d; if(n==0 and d==0)break;
        getchar();
        getline(cin, num);

        apagados = 0;
        tp = 0;

        for(int i=0; i<n; i++){
            c = num[i];

            while(!pilha.empty() and c > pilha.top() and apagados<d){
                pilha.pop();
                apagados++;
                tp--;
            }
            if(tp<n-d){
                pilha.push(c);
                tp++;
            }
            else if(apagados == d){
                break;
            }
        }

        while(!pilha.empty()){
            imprimir.push(pilha.top());
            pilha.pop();
        }
        while(!imprimir.empty()){
            cout << imprimir.top();
            imprimir.pop();
        }
        cout << endl;
    }

    return 0;
}

