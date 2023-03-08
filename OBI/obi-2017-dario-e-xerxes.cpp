// 01/08/2019 // 8:50 PM //

#include <iostream>

using namespace std;

int n;
int d, x, resp=0;

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> d >> x;

        if( (d+1)%5==x || (d+2)%5 == x) resp++;
        else                            resp--;

    }

    resp>0 ? cout << "dario\n": cout << "xerxes\n";

    return 0;
}
