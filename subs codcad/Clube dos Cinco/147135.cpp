// 06/06/19 // 4:44 PM //
// O(1) //

#include <iostream>

using namespace std;

int n, a, b, c ,d ,e, f ,g;

int main(){
    cin >> n >> a >> b >> c >> d >> e >> f >> g;

    cout << ((a + b + c + g - d - e - f)!=n ? "S\n" : "N\n");

    return 0;
}
