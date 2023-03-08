// 28/05/19 // 8:44 PM //

#include <iostream>

using namespace std;

int n, a, b, c;
int qnt[10];

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;

        qnt[temp]++;

        temp = min(qnt[1], min(qnt[3], qnt[5]) );
        a += temp;
        qnt[1] -= temp;
        qnt[3] -= temp;
        qnt[5] -= temp;

        temp = min(qnt[1], qnt[4]);
        b += temp;
        qnt[1] -= temp;
        qnt[4] -= temp;

        temp = min(qnt[2], qnt[4]);
        c += temp;
        qnt[2] -= temp;
        qnt[4] -= temp;
    }

    cout << "A: " << a << "\n";
    cout << "B: " << b << "\n";
    cout << "C: " << c << "\n";

    return 0;
}
