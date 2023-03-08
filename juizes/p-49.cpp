#include <iostream>
using namespace std;

int main(){
    int a,b,c;

    cin >> a >> b >> c;

    if(a==b and b==c){
        cout << "equilatero" <<endl;
    }
    else if(a==b or a==c or b==c){
        cout << "isosceles" <<endl;
    }
    else{
        cout << "escaleno" <<endl;
    }

    return 0;
}
