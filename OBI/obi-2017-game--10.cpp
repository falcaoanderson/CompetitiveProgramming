// 09/05/19 // 6:04 PM //

#include <iostream>

using namespace std;

int main(){
    int n, d, a;

    cin >> n >> d >> a;

    if(d>=a)
        cout << d - a << "\n";
    else
        cout << n - a + d << "\n";

    return 0;
}
