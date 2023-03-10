// 30/01/19 // 21:33 //

#include <iostream>

using namespace std;

int temp, n, total;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    cin >> temp;
    total = temp;
    for(int i=1; i<n; i++){
        cin >> temp;
        total |= temp;
    }

    cout << total << "\n";

    return 0;
}
