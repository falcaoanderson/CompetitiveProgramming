#include <iostream>
using namespace std;

unsigned long long a, b;

unsigned long long mdc(int x, int y){
    if(y==0) return x;
    return mdc(y, x%y);
}

unsigned long long mmc(int x, int y){
    return x*(y/mdc(x, y));
}

int main(){
    cin >> a >> b;

    cout << mmc(a, b) << endl;

    return 0;
}
