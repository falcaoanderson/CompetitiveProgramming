// 10/02/19 // 4:08 //

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b ,c ,d;

    cin >> a >> b >> c >> d;

    cout << min( abs(a+b -c-d), min(abs(a+c-b-d), abs(a+d-b-c))) << "\n";

    return 0;
}
