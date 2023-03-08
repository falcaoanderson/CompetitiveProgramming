#include <iostream>
using namespace std;

int main(){
    float total,pre,quant;

    cin >> total;

    for(int i=0; i<3; i++){
        cin >> quant >> pre;
        total += quant*pre;
    }

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << total << endl << total/21 << endl;
    return 0;
}
