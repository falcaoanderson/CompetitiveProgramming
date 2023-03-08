#include <iostream>
#include <queue>
using namespace std;

int main(){ // A = 65 , P = 80
    queue<char> etap1;
    queue<char> etap2;
    int g1, g2;

    for(int i=65; i<=80; i++)etap1.push(char(i));

    for(int i=0; i<8; i++){
        cin >> g1 >> g2;
        if(g1>g2){
            etap2.push(etap1.front());
            etap1.pop();
            etap1.pop();
        }
        else{
            etap1.pop();
            etap2.push(etap1.front());
            etap1.pop();
        }
    }
    for(int i=0; i<4; i++){
        cin >> g1 >> g2;
        if(g1>g2){
            etap1.push(etap2.front());
            etap2.pop();
            etap2.pop();
        }
        else{
            etap2.pop();
            etap1.push(etap2.front());
            etap2.pop();
        }
    }

    for(int i=0; i<2; i++){
        cin >> g1 >> g2;
        if(g1>g2){
            etap2.push(etap1.front());
            etap1.pop();
            etap1.pop();
        }
        else{
            etap1.pop();
            etap2.push(etap1.front());
            etap1.pop();
        }
    }

    cin >> g1 >> g2;
    if(g1>g2){
        cout << etap2.front() << endl;
    }
    else{
        etap2.pop();
        cout << etap2.front() << endl;
    }

    return 0;
}