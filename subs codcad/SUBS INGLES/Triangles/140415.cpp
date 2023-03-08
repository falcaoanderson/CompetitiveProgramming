// 24/02/19 // 16:02 //

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int lados[5];

    cin >> lados[1] >> lados[2] >> lados[3];

    sort(lados+1, lados+4);

    if(lados[1]>=lados[2]+lados[3] || lados[2]>=lados[1]+lados[3] || lados[3]>=lados[2]+lados[1])
        cout << "n\n";
    else{
        if(lados[3]*lados[3] == lados[2]*lados[2] + lados[1]*lados[1])
            cout << "r\n";
        else if(lados[3]*lados[3] < lados[2]*lados[2] + lados[1]*lados[1])
            cout << "a\n";
        else if(lados[3]*lados[3] > lados[2]*lados[2] + lados[1]*lados[1])
            cout << "o\n";
    }

    return 0;
}
