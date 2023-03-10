// 25/02/19 // 5:15 PM//

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x_r, y_r, x_a, y_a, pontos=0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x_r >> y_r >> x_a >> y_a;

        pontos += (x_r - x_a)*(x_r - x_a) + (y_r - y_a)*(y_r - y_a);
    }

    cout << pontos << "\n";

    return 0;
}
