#include <iostream>
using namespace std;

int main(){
    string op;
    int dias;
    float total;
    char teste;

    getline(cin,op);
    cin >> dias;

    if(dias>=3){
        if(op.size()==10){
            total = 125*dias*0.85;
        }
        else if(tolower(op[6])=='d'){
            total = 140*dias*0.85;
        }
        else{
            total = 180*dias*0.85;
        }
    }
    else{
        if(op.size()==10){
            total = 125*dias;
        }
        else if(tolower(op[6])=='d'){
            total = 140*dias;
        }
        else{
            total = 180*dias;
        }
    }

    cout.precision(2);
    cout.setf(ios::fixed);
    cout << total << endl;

    return 0;
}
