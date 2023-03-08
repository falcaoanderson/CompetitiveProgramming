#include <iostream>
using namespace std;

int main(){
    int c, a;
    cin >> c >> a;

    int viagens = a/(c-1);

    if(a%(c-1)==0)
        cout << viagens << endl;
    else
        cout << viagens + 1 << endl;

    return 0;
}
