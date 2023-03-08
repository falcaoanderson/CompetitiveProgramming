#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l1, r1, l2, r2;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> l1 >> r1 >> l2 >> r2;

        if(l1<=l2){
            cout << l1 << " " << r2 << "\n";
        }
        else{
            cout << r1 << " "<< l2 << "\n";
        }
    }

    return 0;
}
