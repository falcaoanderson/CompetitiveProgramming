// 24/02/19 // 4:17 PM //

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x_m, y_m, x_r, y_r;

    cin >> x_m >> y_m >> x_r >> y_r;

    cout << abs(x_m - x_r) + abs(y_m - y_r) << "\n";

    return 0;
}
