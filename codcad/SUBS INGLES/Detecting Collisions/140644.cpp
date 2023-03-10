// 25/02/19 // 6:20 PM //

#include <iostream>

using namespace std;

bool entre(int a, int b, int c){
    if(a<=b && b<=c)
        return 1;
    else
        return 0;
}

int x_1, x_2, y_1, y_2;
int x_a, x_b, y_a, y_b;

int main(){
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    cin >> x_a >> y_a >> x_b >> y_b;

    int saida=0;

    if( (entre(x_a,x_1,x_b)||entre(x_a,x_2,x_b)) && (entre(y_1,y_a,y_2)||entre(y_1,y_b,y_2)) )
        saida=1;
    else if( (entre(x_1,x_a,x_2)||entre(x_1,x_b,x_2)) && (entre(y_a,y_1,y_b)||entre(y_a,y_2,y_b)) )
        saida=1;
    else if ( x_1<=x_a && x_b<=x_2 && y_1<=y_a && y_b<=y_2)
        saida = 1;
    else if ( x_a<=x_1 && x_2<=x_b && y_a<=y_1 && y_2<=y_b)
        saida = 1;

    cout << saida << "\n";

    return 0;
}
