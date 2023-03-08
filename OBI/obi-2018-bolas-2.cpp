// 31/03/19 // 1:15 PM //

#include <iostream>

using namespace std;

int v[18], temp;
char resp='S';

int main(){

    for(int i=0; i<8; i++){
        cin >> temp;
        v[temp]++;
    }

    for(int i=0; i<=9; i++)
        if(v[i]>4)
            resp = 'N';

    cout << resp << "\n";

    return 0;
}
