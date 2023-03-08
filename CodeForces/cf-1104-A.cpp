// 22/01/19 // 10:46 PM//

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << n << "\n";

    for(int i=0; i<n-1; i++){
        cout << "1 ";
    }
    cout << "1\n";

    return 0;
}
