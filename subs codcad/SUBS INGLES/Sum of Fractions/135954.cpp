// 14/01/2019 // 1 PM //

#include <iostream>
using namespace std;

long long a, b, c, d, dividendo, divisor;

long long mdc(long long x, long long y){
    if(y==0) return x;
    return mdc(y, x%y);
}

long long mmc(long long x, long long y){
    return (x*y)/mdc(x,y);
}

int main(){
    cin >> a >> b >> c >> d;

    divisor = mmc(b, d);
    dividendo = a*(divisor/b) + c*(divisor/d);

    a = mdc(dividendo, divisor);
    divisor /= a;
    dividendo /= a;

    cout << dividendo << " " << divisor << endl;

    return 0;
}
