#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<char> etapa;
    int g1,g2;

    for(char i='A'; i<='P'; i++)etapa.push(char(i));

    for(int i=0; i<15; i++){
        cin >> g1 >> g2;
        if(g1>g2){
            etapa.push(etapa.front());
            etapa.pop();
            etapa.pop();
        }
        else{
            etapa.pop();
            etapa.push(etapa.front());
            etapa.pop();
        }
    }
    cout << etapa.front() << endl;
    return 0;
}