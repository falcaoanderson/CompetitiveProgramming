#include <iostream>
using namespace std;

int main(){
    float p1, p2, p3, total;
    int qnt1, qnt2, qnt3;

    cin >> p1 >> p2 >> p3 >> qnt1 >> qnt2 >> qnt3;
    total = p1*qnt1 + p2*qnt2 + p3*qnt3;

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << "Valor: R$" << total << endl;
    return 0;
}
