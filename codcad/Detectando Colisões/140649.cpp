// 25/02/19 // 6:20 PM //

#include <iostream>

using namespace std;

int main(){
    int x_1, x_2, y_1, y_2;
    int x_a, x_b, y_a, y_b;

    cin >> x_1 >> y_1 >> x_2 >> y_2;
    cin >> x_a >> y_a >> x_b >> y_b;

    int saida = 1;

    if(x_2<x_a || y_2<y_a || x_b<x_1 || y_b<y_1)
        saida = 0;

    cout << saida << "\n";

    return 0;
}
